class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n= grid[0].size();

        if(grid[0][0]==1 || grid[m-1][n-1]==1){
            return -1;
        }

        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({1,{0,0}});

        int delrow[]= {-1,-1,0,1,1,1,0,-1};
        int delcol[]= {0,1,1,1,0,-1,-1,-1};

        while(!pq.empty()){
            int dis= pq.top().first;
            int i= pq.top().second.first;
            int j= pq.top().second.second;
            pq.pop();

            if(i==m-1 && j==n-1){
                return dis;
            }

            for(int k=0;k<8;k++){
                int row= delrow[k]+i;
                int col= delcol[k]+j;

                if(row>=0 && row<m && col>=0 && col<n && grid[row][col]==0){
                    grid[row][col]=1;
                    pq.push({dis+1,{row,col}});
                }
            }
        }

        return -1;
        
    }
};