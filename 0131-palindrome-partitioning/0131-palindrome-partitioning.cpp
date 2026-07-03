class Solution {
public:
bool palindrome(string s,int left,int right){
    while(right>left){
         if(s[left]!=s[right]){
            return false;
         }
         left++;
         right--;
    }
    return true;
}
void helper(vector<vector<string>>& res,vector<string>& curr,string s,int start){
    if(start==s.length()){
        res.push_back(curr);
        return;
    }

    for(int end=start;end<s.length();end++){
        if(palindrome(s,start,end)){
            curr.push_back(s.substr(start,end-start+1));
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