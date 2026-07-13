class Solution {
public:
    vector<vector<string>> solutions;
    unordered_set<int> cols;
    unordered_set<int> posDiagonal;
    unordered_set<int> negDiagonal;

    void build(int row,int n,vector<string> &curr){
        if(row==n){
            solutions.push_back(curr);
            return;
        }

        for(int col=0;col<n;col++){
            if(cols.count(col) || posDiagonal.count(row+col) || negDiagonal.count(row-col)) continue;

            curr[row][col]='Q';
            cols.insert(col);
            posDiagonal.insert(row+col);
            negDiagonal.insert(row-col);

            build(row+1,n,curr);

            curr[row][col]='.';
            cols.erase(col);
            posDiagonal.erase(row+col);
            negDiagonal.erase(row-col);
        }
    }
    vector<vector<string>> solveNQueens(int n) {

        vector<string> curr(n,string (n,'.'));
        build(0,n,curr);
        return solutions;
        
    }
};