class Solution {
public: 
    void dfs(int i,int j,vector<vector<char>>& board,int delrow[],int delcol[],int m,int n){
        board[i][j]='#';

        for(int k=0;k<4;k++){
            int row= delrow[k]+i;
            int col= delcol[k]+j;

            if(row<m && row>=0 && col<n && col>=0){
                if(board[row][col]=='O'){
                    dfs(row,col,board,delrow,delcol,m,n);
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {

        int m=board.size();
        int n=board[0].size();

        int delrow[]= {0,1,0,-1};
        int delcol[]= {1,0,-1,0};

        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
              dfs(i,0,board,delrow,delcol,m,n);
            }
            if(board[i][n-1]=='O'){
                dfs(i,n-1,board,delrow,delcol,m,n);
            }
        }

        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
              dfs(0,i,board,delrow,delcol,m,n);
            }
            if(board[m-1][i]=='O'){
                dfs(m-1,i,board,delrow,delcol,m,n);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }else if (board[i][j] == '#') {
                    board[i][j] = 'O'; 
                }
            }
        }
        
    }
};