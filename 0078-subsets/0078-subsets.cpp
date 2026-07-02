class Solution {
public:
    void helper(int start,vector<int> nums,vector<vector<int>> &res,vector<int> curr){
        res.push_back(curr);

        for(int i=start;i<nums.size();i++){
            curr.push_back(nums[i]);
            helper(i+1,nums,res,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;

        helper(0,nums,res,curr);
        return res;
        
    }
};