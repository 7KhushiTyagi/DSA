class Solution {

public:
    bool possible(int mid,vector<int>& nums,int n){
        int count=0;
        for(int num:nums){
            count+= (num+mid-1)/mid;
            if(count>n) return false;
        }
        return count<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();
        int low= 1;
        int high= *max_element(quantities.begin(),quantities.end());

        while(low<=high){
            int mid= low+(high-low)/2;

            if(possible(mid,quantities,n)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
        
    }
};