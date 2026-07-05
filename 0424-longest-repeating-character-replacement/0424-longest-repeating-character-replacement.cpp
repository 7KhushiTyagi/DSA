class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        unordered_map<char,int> map;
        int max_count=0;
        int max_length=0;

        for(int right=0;right<s.length();right++){
            map[s[right]-'A']++;
            max_count= max(max_count,map[s[right]-'A']);

            while((right-left+1)-max_count>k){
                map[s[left]-'A']--;
                left++;
            }
            max_length=max(max_length,right-left+1);
        }
        return max_length;
        
    }
};