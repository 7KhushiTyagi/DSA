class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,int delrow[],int delcol[]){
        grid[i][j]=0;
        int m=grid.size();
        int n=grid[0].size();
        

      for(int k=0;k<4;k++){
        int row= i+delrow[k];
        int col= j+delcol[k];

        if(row>=0 && row<m && col>=0 && col<n && grid[row][col]==1){
            dfs(row,col,grid,delrow,delcol);
        }
      }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};

        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                dfs(i,0,grid,delrow,delcol);
            }
            if(grid[i][n-1]==1){
                dfs(i,n-1,grid,delrow,delcol);
            }
            
        }
        for(int i=0;i<n;i++){
            if(grid[0][i]==1){
                dfs(0,i,grid,delrow,delcol);
            }
            if(grid[m-1][i]==1){
                dfs(m-1,i,grid,delrow,delcol);
            }
            
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
        
    }
};