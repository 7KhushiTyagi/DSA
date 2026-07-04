class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int m= image.size();
        int n= image[0].size();

        int delrow[]= {0,1,0,-1};
        int delcol[]= {1,0,-1,0};

        int start= image[sr][sc];
        if (start == color) return image;

        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;

        while(!q.empty()){
            int i= q.front().first;
            int j= q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int row = i +delrow[k];
                int col= j+ delcol[k];

                if(row<m && row>=0 && col>=0 && col<n){
                  if(image[row][col]==start){
                    q.push({row,col});
                    image[row][col]=color;

                  }
                }
            }
        }
        return image;
        
    }
};