class Solution {
public:
    bool isvowel(char c){
        if((c=='a') || (c=='e') || (c=='i') || (c=='o') || (c=='u')){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {

        int curr=0;
        for(int i=0;i<k;i++){
            if(isvowel(s[i])){
                curr++;
            }
        }

        int maxi=curr;

        for(int i=k;i<s.length();i++){
            if(isvowel(s[i])){
                curr++;
            }
            if(isvowel(s[i-k])){
                curr--;
            }

            maxi=max(maxi,curr);
            if(curr==k) return k;
        }
        return maxi;
        
    }
};