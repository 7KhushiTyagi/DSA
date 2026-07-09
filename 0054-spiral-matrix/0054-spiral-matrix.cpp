class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        int left=0;
        int right=m-1;
        int top=0;
        int down=n-1;

        vector<int> res;

        while(left<=right && top<=down){

            for(int i=left;i<=right;i++){
                res.push_back(matrix[top][i]);
            }
            top++;

            for(int i=top;i<=down;i++){
                res.push_back(matrix[i][right]);
            }
            right--;

        if(top<=down){
            for(int i=right;i>=left;i--){
                res.push_back(matrix[down][i]);
            }
            down--;
            }

            if(right>=left){
                for(int i=down;i>=top;i--){
                res.push_back(matrix[i][left]);
            }
            left++;
            }
        }
        return res;
        
    }
};