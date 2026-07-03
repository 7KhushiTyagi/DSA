class Solution {
    bool helper(vector<vector<char>>& board,string word,int i,int j,int idx){
        int n=board.size();
        int m=board[0].size();
        if(idx==word.length()){
            return true;
        }
        if(i>=n || i<0 || j>=m || j<0 || board[i][j]!=word[idx]) return false;

        char temp=board[i][j];
        board[i][j]='&';

        bool found= helper(board,word,i+1,j,idx+1) ||
                    helper(board,word,i-1,j,idx+1) ||
                    helper(board,word,i,j-1,idx+1) ||
                    helper(board,word,i,j+1,idx+1);
        
        board[i][j]=temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(helper(board,word,i,j,0)){
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
};