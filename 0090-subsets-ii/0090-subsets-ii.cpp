class Solution {
public:
    void helper(vector<vector<int>>& res,vector<int>& curr,vector<int>& nums,int idx){ 
        
        res.push_back(curr);

        for(int i=idx;i<nums.size();i++){
            if (i > idx && nums[i] == nums[i - 1])
                continue;
            curr.push_back(nums[i]);
            helper(res,curr,nums,i+1);
            curr.pop_back();
        }

        

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
         sort(nums.begin(),nums.end());
        helper(res,curr,nums,0);
        return res;
        
    }
};