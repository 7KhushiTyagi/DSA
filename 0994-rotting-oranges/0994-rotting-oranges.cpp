class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int fresh=0;
        int time=0;
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    fresh++;
                }else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        int delrow[]= {-1,0,1,0};
        int delcol[]= {0,1,0,-1};

        while(!q.empty()){
            int size=q.size();

            bool condition=false;

            for(int i=0;i<size;i++){
                int row= q.front().first;
                int col= q.front().second;
                q.pop();

                for(int k=0;k<4;k++){
                    int new_row= delrow[k]+row;
                    int new_col= delcol[k]+col;

                    if(new_row>=0 && new_row<m && new_col>=0 && new_col<n){
                        if(grid[new_row][new_col]==1){
                            grid[new_row][new_col]=2;
                            condition=true;
                            q.push({new_row, new_col});
                            fresh--;

                        }
                    }
                }
            }
            if(condition==true){
                time++;
            }

        }

        return fresh==0 ? time : -1; 

        
    }
};