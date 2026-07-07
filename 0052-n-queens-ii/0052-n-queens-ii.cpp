
class Solution {
    public:
    vector<vector<string>> solutions;
    unordered_set<int> cols;
    unordered_set<int> positiveDiagonal;
    unordered_set<int> negativeDiagonal;


    void helper(int row,int n,vector<string>& board){
        if(row==n){
          solutions.push_back(board);
          return;
        }

        for(int col=0;col<n;col++){
            if(cols.count(col) || positiveDiagonal.count(col+row) || negativeDiagonal.count(row-col)){
                continue;
            }

            board[row][col]='Q';
            cols.insert(col);
            positiveDiagonal.insert(col+row);
            negativeDiagonal.insert(row-col);
            helper(row+1,n,board);

            board[row][col]='.';
            cols.erase(col);
            positiveDiagonal.erase(col+row);
            negativeDiagonal.erase(row-col);

        }
    }
    int totalNQueens(int n) {
        vector<string> board(n,string (n,'.'));
        helper(0,n,board);
        return solutions.size();
        
    }
};