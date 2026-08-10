class Solution {
public:
    string minWindow(string s, string t) {
        int m= s.length();
        int n= t.length();
        unordered_map<char,int> map;

        if(m<n || n==0) return "";

        for(int c:t){
            map[c]++;
        }

        int left=0;int right=0;
        int count=0;
        int mini= INT_MAX;
        int start=-1;

        while(right<m){
            if(map[s[right]]>0){
                count++;
            }

            map[s[right]]--;

            while(count==n){
                if((right-left+1)<mini){
                    mini= right-left+1;
                    start= left;
                }

                map[s[left]]++;

                if(map[s[left]]>0){
                    count--;
                }
                left++;

            }
            right++;

        }

        return (start==-1)? "" : s.substr(start,mini);
        
    }
};