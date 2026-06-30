class Solution {
public:
    bool possible(int mid,int k,vector<int> nums){
        int sum=0;
        int count=1;

        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>mid){
                count++;
                if(count>k) return false;
                sum=0;
            }
            sum+=nums[i];
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int low= *max_element(nums.begin(),nums.end());
        int high= accumulate(nums.begin(),nums.end(),0);
        int ans=-1;

        while(high>=low){
            int mid = low+(high-low)/2;

            if(possible(mid,k,nums)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
        
        
    }
};