class Solution {
public:
    vector<int> row(int r){
        vector<int> singleRow;
        long long ans=1;
        singleRow.push_back(ans);

        for(int i=1;i<r;i++){
            ans= ans*(r-i);
            ans= ans/i;
            singleRow.push_back(ans);
        }
        return singleRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for(int i=1;i<=numRows;i++){
            res.push_back(row(i));
        }
        return res;
        
    }
};