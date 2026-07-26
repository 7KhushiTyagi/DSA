class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();

        vector<vector<int>> dp(n,vector<int> (n,0));

        for(int i=0;i<n;i++){
            dp[0][i]= matrix[0][i];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int straight = dp[i - 1][j];
                
                
                int leftDiagonal = (j > 0) ? dp[i - 1][j - 1] : 1e9;
                
                
                int rightDiagonal = (j < n - 1) ? dp[i - 1][j + 1] : 1e9;

                dp[i][j] = matrix[i][j] + min({straight, leftDiagonal, rightDiagonal});
            }
        }

        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,dp[n-1][i]);
        }

        return mini;
        
    }
};