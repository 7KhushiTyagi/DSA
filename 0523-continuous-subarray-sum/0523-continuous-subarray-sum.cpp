class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum=0;
        unordered_map<int,int> map;
        map[0]=-1;
        bool cond=false;
        

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem= sum%k;

            if(map.find(rem)!=map.end()){
               if (i - map[rem] >= 2) {
                    cond = true;
                    break;
                }
            }else{
            map[rem]=i;
            }
        }

        

        return cond;


        
    }
};