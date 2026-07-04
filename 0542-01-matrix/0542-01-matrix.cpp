class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>> res(m,vector<int> (n,-1));

        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    res[i][j]=0;
                }
            }
        }

        int delrow[]= {-1,0,1,0};
        int delcol[]= {0,1,0,-1};

        while(!q.empty()){
            int i= q.front().first;
            int j= q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int row= delrow[k]+i;
                int col= j+delcol[k];

                if(row<m && row>=0 && col<n && col>=0){
                    if(res[row][col]==-1){
                        q.push({row,col});
                        res[row][col]= 1+res[i][j];
                    }
                }
            }
        }
        return res;
        
    }
};