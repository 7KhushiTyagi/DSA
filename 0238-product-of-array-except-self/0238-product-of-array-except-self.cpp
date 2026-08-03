class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n=nums.size();
        vector<int> res(n);

        int pre=1;
        int suff=1;

        for(int i=0;i<n;i++){
            res[i]= pre;
            pre= pre*nums[i];
        }

        for(int i=n-1;i>=0;i--){
            res[i]= res[i]*suff;
            suff= suff*nums[i];
        }

        return res;

        
    }
};