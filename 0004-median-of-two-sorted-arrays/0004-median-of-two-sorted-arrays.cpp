class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m= nums2.size();
        int N = n+m;

        int i=0;int j=0;
        int ele2=-1; int ele1=-1;
        int count=0;
        int idx2=N/2; int idx1= idx2-1;

        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
               if(count==idx1) ele1=nums1[i];
               if(count==idx2) ele2=nums1[i];
               i++;
            }else{
            if(count==idx1)  ele1=nums2[j];
               if(count==idx2) ele2=nums2[j];
               j++;

            }
            count++;

        }
        while(i<n){
            if(count==idx1) ele1=nums1[i];
               if(count==idx2) ele2=nums1[i];
               i++;
               count++;

        }
        while(j<m){
            if(count==idx1) ele1=nums2[j];
               if(count==idx2) ele2=nums2[j];
               j++;
               count++;

        }

        if(N%2==0){
            return (double)((double)(ele1+ele2))/2.0;
        }
        return ele2;
        
    }
};