
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        
        vector<vector<vector<int>>> dp(rows + 1, vector<vector<int>>(cols, vector<int>(cols, 0)));
        
        for (int r = rows - 1; r >= 0; --r) {
            for (int c1 = 0; c1 < cols; ++c1) {
                for (int c2 = 0; c2 < cols; ++c2) {
                    
                    int currentCherries = (c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2];
                    int maxNext = 0;
                    
                   
                    for (int dc1 = -1; dc1 <= 1; ++dc1) {
                        for (int dc2 = -1; dc2 <= 1; ++dc2) {
                            int nc1 = c1 + dc1;
                            int nc2 = c2 + dc2;
                            
                            if (nc1 >= 0 && nc1 < cols && nc2 >= 0 && nc2 < cols) {
                                maxNext = max(maxNext, dp[r + 1][nc1][nc2]);
                            }
                        }
                    }
                    
                    dp[r][c1][c2] = currentCherries + maxNext;
                }
            }
        }
        
        return dp[0][0][cols - 1];
    }
};