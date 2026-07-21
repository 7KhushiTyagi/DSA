class Solution {
public:
    void helper(int n,int open,int close,vector<string>& res,string curr){
        

        if(curr.size()==2*n){
            res.push_back(curr);
            return;
        }

        if(open<n){
            helper(n,open+1,close,res,curr+'(');
        }
        if(close<open){
            helper(n,open,close+1,res,curr+')');
        }


    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;

        helper(n,0,0,res,curr);
        return res;
        
    }
};