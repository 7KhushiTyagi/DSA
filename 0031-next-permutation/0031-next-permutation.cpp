class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int idx=n-2;

        while(idx>=0 && nums[idx]>=nums[idx+1]){ //break point
            idx--;
        }

        if(idx>=0){
            int j=n-1;

            while(nums[j]<=nums[idx]){
                j--;
            }
            swap(nums[j],nums[idx]);
        }
        reverse(nums.begin()+idx+1,nums.end());
        
        
    }
};