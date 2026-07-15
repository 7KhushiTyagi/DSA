class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;

        for(int num:stones){
            sum+=num;
        }

        int target= sum/2;

        vector<bool> dp(target+1,false);
        dp[0]=true;

        for(int stone:stones){
            for(int i=target;i>=stone;i--){
                dp[i]= dp[i] || dp[i-stone];
            }
        }

        for(int i=target;i>=0;i--){
            if(dp[i]){
                return sum-2*i;
            }
        }

        return 0;

        
    }
};