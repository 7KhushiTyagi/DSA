#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int minutes = 0;
        int fresh = 0;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        queue<pair<int, int>> q;

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        if (fresh == 0) return 0;

        
        while (!q.empty()) {
            int size = q.size(); 
           
            bool rottedAnyThisMinute = false;

            for (int i = 0; i < size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int new_row = row + delrow[d];
                    int new_col = col + delcol[d];

                    
                    if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n) {
                        
                        if (grid[new_row][new_col] == 1) {
                            grid[new_row][new_col] = 2; 
                            q.push({new_row, new_col});
                            fresh--;
                            rottedAnyThisMinute = true;
                        }
                    }
                }
            }
            
            
            if (rottedAnyThisMinute) {
                minutes++;
            }
        }

        return (fresh == 0) ? minutes : -1;
    }
};