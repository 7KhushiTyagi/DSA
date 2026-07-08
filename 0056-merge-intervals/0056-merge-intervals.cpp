class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());

        for(auto &ele:intervals){
            if(res.empty() || res.back()[1]<ele[0]){
                res.push_back({ele[0],ele[1]});
            }else{
                res.back()[1]=max(ele[1],res.back()[1]);
            }
        }
        return res;

        
    }
};