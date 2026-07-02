void helper(vector<string> &res,string curr,int n,int open,int close){

    if(curr.size()==2*n){
        res.push_back(curr);
        return;
    }
    if(open<n){
        helper(res,curr+"(",n,open+1,close);
    }
    if(close<open){
        helper(res,curr+")",n,open,close+1);
    }
}


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
         helper(res,"",n,0,0);
         return res;
        
    }
};
