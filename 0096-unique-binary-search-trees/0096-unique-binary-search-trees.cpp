class Solution {
public:
    int numTrees(int n) {
        
        vector<int> dp(n + 1, 0);
        
        
        dp[0] = 1; 
        dp[1] = 1; 
        
        
        for (int total_nodes = 2; total_nodes <= n; total_nodes++) {
            for (int root = 1; root <= total_nodes; root++) {
                int left_nodes = root - 1;
                int right_nodes = total_nodes - root;
                
                dp[total_nodes] += dp[left_nodes] * dp[right_nodes];
            }
        }
        
        return dp[n];
    }
};