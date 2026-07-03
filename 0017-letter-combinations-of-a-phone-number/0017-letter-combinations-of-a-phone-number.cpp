class Solution {
public:
    unordered_map<char, string> mp = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};
    void helper(vector<string>& res,string& curr,string& digits,int start){
        if(start==digits.length()){
            res.push_back(curr);
            return;
        }

        char c = digits[start];

        for(auto it: mp[c]){
            curr.push_back(it);
            helper(res,curr,digits,start+1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        vector<string> res;
        string curr;

        helper(res,curr,digits,0);
        return res;
        
    }
};