class Solution {
public:
    string reverseWords(string s) {
        int right= s.length()-1;
        string res=""; 

        while(right>=0){
            while(right>=0 && s[right]==' '){
                right--;
            }

            if (right < 0) break;
            int i=right;
            while(i>=0 && s[i]!=' '){
                i--;
            }

            if(res.length()==0){
                res+=s.substr(i+1,right-i);
            }else{
                res= res+ " "+s.substr(i+1,right-i);
            }
            right=i-1;

        }
        return res;
    }
};