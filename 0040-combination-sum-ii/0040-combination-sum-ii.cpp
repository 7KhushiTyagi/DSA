void method(vector<vector<int>>  &res,vector<int> &curr,vector<int> candidates,int target,int start){
    if(target==0){
        res.push_back(curr);
        return;
    }
    
    for(int i=start;i<candidates.size();i++){
        if(i>start && candidates[i]==candidates[i-1]){
            continue;
        }
        if(candidates[i]>target){
            break;
        }
        curr.push_back(candidates[i]);
        method(res,curr,candidates,target-candidates[i],i+1);
        curr.pop_back();


    }
}
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        method(res,curr,candidates,target,0);
        return res;

        
    }
};
