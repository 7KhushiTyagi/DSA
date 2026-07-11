class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();

        if(m<n) return false;

        vector<int> s1count(26,0);
        vector<int> s2count(26,0);

        for(int i=0;i<n;i++){
            s1count[s1[i]-'a']++;
            s2count[s2[i]-'a']++;
        }
        if(s1count==s2count) return true;

        for(int i=n;i<m;i++){
            s2count[s2[i]-'a']++;
            s2count[s2[i-n]-'a']--;
            if(s1count==s2count) return true;
        }
        return false;
        
    }
};