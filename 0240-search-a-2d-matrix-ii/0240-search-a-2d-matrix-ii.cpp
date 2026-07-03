class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();

        int low=0;
        int high=col-1;

        while(low<row && high>=0){
            int mid=matrix[low][high];

            if(mid==target){
                return true;
            }else if(mid>target){
                high--;
            }else{
                low++;
            }
        }
        return false;
        
    }
};