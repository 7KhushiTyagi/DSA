class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;

        unordered_map<int,int> map;

        for(int num:nums){
            map[num]++;
        }

        vector<pair<int,int>> arr(map.begin(),map.end());

        sort(arr.begin(),arr.end(),[](const pair<int,int> &a,const pair<int,int> &b){
            return a.second>b.second;
        });

        for(int i=0;i<k;i++){
            res.push_back(arr[i].first);
        }

        return res;
        
    }
};