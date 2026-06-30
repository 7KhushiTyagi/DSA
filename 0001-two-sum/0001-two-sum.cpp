class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> map; // <number,idx>

        for(int i=0;i<nums.size();i++){
            int k= target-nums[i];
            if(map.find(k)!=map.end()){
                return {i,map[k]};
            }
            map[nums[i]]=i;
        }
        return {-1,-1};
        
    }
};