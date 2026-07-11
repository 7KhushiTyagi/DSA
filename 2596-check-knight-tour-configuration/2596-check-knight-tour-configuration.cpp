class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();

        if(grid[0][0]!=0) return false;

        vector<pair<int,int>> positions(n*n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int step= grid[i][j];
                positions[step]= {i,j};
            }
        }

        for(int i=1;i<n*n ;i++){
            auto [prevRow,prevCol]= positions[i-1];
            auto [currRow,currCol]= positions[i];

            int rowDiff= abs(currRow-prevRow);
            int colDiff= abs(currCol-prevCol);

            if(!((rowDiff==2 && colDiff==1) || (rowDiff==1 && colDiff==2)))
            return false;

        }
        return true;

        
    }
};