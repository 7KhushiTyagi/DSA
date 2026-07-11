class Solution {
public:
    bool palindrome(string s,int start,int end){
        while(end>=start){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void helper(vector<vector<string>>& res,vector<string>& curr,string s,int i){
        if(i==s.length()){
            res.push_back(curr);
            return;
        }

        for(int end=i;end<s.length();end++){
            if(palindrome(s,i,end)){
                string str= s.substr(i,end-i+1);
                curr.push_back(str);
                helper(res,curr,s,end+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;

        helper(res,curr,s,0);
        return res;
        
    }
};