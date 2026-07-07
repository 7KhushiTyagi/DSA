class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>> res;

        for(int i=0;i<n-1;i++){

            if(i>0 && nums[i-1]==nums[i]) continue;

            int left=i+1;
            int right= n-1;

            while(left<right){
                int sum= nums[left]+nums[right]+nums[i];

                if(sum==0){
                    res.push_back({nums[left],nums[right],nums[i]});

                    while(left<right && nums[left]==nums[left+1]) left++;
                    while(left<right && nums[right]==nums[right-1]) right--;
                    left++;
                    right--;
                }
                else if(sum>0){
                    right--;
                }else{
                    left++;
                }
            }
        }
        return res;
        
    }
};