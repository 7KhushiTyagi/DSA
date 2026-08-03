class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        
        string res="";
        string first= strs[0];
        string last= strs[n-1];

        for(int i=0;i<first.length();i++){
            if(first[i]==last[i]){
                res+= first[i];
            }else{
                break;
            }
        }

        return res;
        
    }
};