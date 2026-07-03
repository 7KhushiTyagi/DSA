class Solution {
public:
    bool pred(string str,string pred){
        if(str.length()!=pred.length()+1) return false;
        
        int n=str.length(); int m=pred.length();
        int i=0;int j=0;

        while(i<n){
            if(j<m && str[i]==pred[j]){
                i++;j++;
            }else{
                i++;
            }
        }
        return j==m;
    }

    int longestStrChain(vector<string>& words) {
        int maxi=1;
        int n=words.size();

        vector<int> dp(n,1);

        sort(words.begin(), words.end(),
     [](string &a, string &b) {
         return a.size() < b.size();
     });

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(pred(words[i],words[j])){
                    dp[i]= max(dp[i],dp[j]+1);
                }
            }
            maxi=max(dp[i],maxi);
        }
        return maxi;
        
    }
};