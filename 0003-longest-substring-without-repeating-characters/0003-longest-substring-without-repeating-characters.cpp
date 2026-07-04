class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int left=0;
        int right=0;
        int maxLen=0;

        unordered_map<char,int> map;

        while(right<n){
            if(map.find(s[right])!=map.end()){
                left= max(left,1+map[s[right]]);
            }
            maxLen=max(maxLen,right-left+1);
            map[s[right]]= right;
            right++;
        }

        return maxLen;

        
    }
};