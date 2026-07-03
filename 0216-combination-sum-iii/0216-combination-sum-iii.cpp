class Solution {
public:
    void helper(vector<vector<int>>& res,vector<int>& curr,int k,int n,int i){
        if(k==0 && n==0){
            res.push_back(curr);
            return;
        }
        if(k<0 || n<0 || i>9) return;

        for(int j=i;j<=9;j++){
            curr.push_back(j);
            helper(res,curr,k-1,n-j,j+1);
            curr.pop_back();
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;

        helper(res,curr,k,n,1);
        return res;
        
    }
};