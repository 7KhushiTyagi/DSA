class Solution {
public:
    void helper(vector<vector<int>> &res,vector<int> &curr,vector<int> &candidates,int target,int start){

        if(target==0){
            res.push_back(curr);
            return;
        }
      if(target<0) return;

        for(int i=start;i<candidates.size();i++){
            curr.push_back(candidates[i]);
            helper(res,curr,candidates,target-candidates[i],i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;

        helper(res,curr,candidates,target,0);
        return res;
        
    }
};