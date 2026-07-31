class Solution {
public:
    void dfs(int m,int n,vector<vector<char>>& board,int delrow[],int delcol[],int i,int j){

        board[i][j]='#';

        for(int k=0;k<4;k++){
            int row= i+ delrow[k];
            int col= j+ delcol[k];

            if(row>=0 && col>=0 && row<m && col<n && board[row][col]=='O'){
                dfs(m,n,board,delrow,delcol,row,col);
            }
        }
    }
    void solve(vector<vector<char>>& board) {

        int m=board.size();
        int n=board[0].size();

        int delrow[]= {-1,0,1,0};
        int delcol[]= {0,1,0,-1};

        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                dfs(m,n,board,delrow,delcol,i,0);
            }
            if(board[i][n-1]=='O'){
                dfs(m,n,board,delrow,delcol,i,n-1);
            }

        }

        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                dfs(m,n,board,delrow,delcol,0,i);
            }
            if(board[m-1][i]=='O'){
                dfs(m,n,board,delrow,delcol,m-1,i);
            }

        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }


        
    }
};