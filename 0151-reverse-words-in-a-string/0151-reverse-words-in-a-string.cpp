class Solution {
public:
    string reverseWords(string s) {
        int right= s.length()-1;
        string res="";

        while(right>=0){
            while(right>=0 && s[right]==' '){
                right--;
            }

            if(right<0) return res;
            int i=right;
            while(i>=0 && s[i]!=' '){
                i--;
            }

            if(res.empty()){
                res+= s.substr(i+1,right-i);
            }else{
                res+= " "+ s.substr(i+1,right-i);
            }
            right= i-1;
        }

        return res;
        
    }
};