class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m= mat.size();
        int n= mat[0].size();

        vector<vector<int>> graph(m,vector<int> (n,-1));

        queue<pair<int,int>> q;


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    graph[i][j]=0;
                    q.push({i,j});
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
                int col= delcol[k]+j;

                if(row>=0 && col>=0 && row<m && col<n && graph[row][col]==-1){
                    q.push({row,col});
                    graph[row][col]= 1+graph[i][j];
                }
            }
        }

        return graph;
        
    }
};