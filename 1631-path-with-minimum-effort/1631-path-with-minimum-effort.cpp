
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;
        
        pq.push({0, {0, 0}});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        
        vector<vector<int>> efforts(m, vector<int>(n, 1e9));
        efforts[0][0] = 0;

        while (!pq.empty()) {
            int effort = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            
            if (i == m - 1 && j == n - 1) return effort;

            
            if (effort > efforts[i][j]) continue;

            for (int k = 0; k < 4; k++) {
                int row = delrow[k] + i;
                int col = delcol[k] + j;

                
                if (row < m && row >= 0 && col >= 0 && col < n) {
                    
                    int curr = max(effort, abs(heights[i][j] - heights[row][col]));
                    
                    if (curr < efforts[row][col]) {
                        efforts[row][col] = curr;
                        pq.push({curr, {row, col}});
                    }
                }
            }
        }
        
        
        return 0; 
    }
};