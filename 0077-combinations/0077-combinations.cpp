class Solution {
public:
    void helper(vector<vector<int>>& res,vector<int>& curr,int n,int k,int idx){
        if(curr.size()==k){
            res.push_back(curr);
            return;
        }

        for(int i=idx;i<=n;i++){
            curr.push_back(i);
            helper(res,curr,n,k,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        helper(res,curr,n,k,1);

        return res;

    }
};