class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        unordered_map<char,int> map;

        int ans=0;

        for(int right=0;right<s.length();right++){
            if(map.find(s[right])!=map.end()){
                left= max(left,map[s[right]]+1);
            }

            ans= max(ans,right-left+1);
            map[s[right]]=right;
        }

        return ans;
        
    }
};