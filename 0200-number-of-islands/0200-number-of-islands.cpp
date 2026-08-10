class Solution {
public:
    void dfs(int i,int j,int m,int n,vector<vector<char>>& grid){
        grid[i][j]='0';

        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};

        for(int k=0;k<4;k++){
            int row= delrow[k]+i;
            int col= delcol[k]+j;

            if(row>=0 && col>=0 && row<m && col<n && grid[row][col]=='1'){
            dfs(row,col,m,n,grid);
        }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n= grid[0].size();

        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,m,n,grid);
                    count++;
                }
            }
        }

        return count;
        
    }
};