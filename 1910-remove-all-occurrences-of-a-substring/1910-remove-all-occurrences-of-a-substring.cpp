class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res="";

        for(char c:s){
            res.push_back(c);

            if(res.length()>=part.length() && res.substr(res.length()-part.length())==part){
                res.erase(res.length()-part.length());
            }
        }
        return res;
        
    }
};