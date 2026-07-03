class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);

        if(n==0) return {};
        vector<int> res;

        sort(nums.begin(),nums.end());

        int maxi=1;
        int last=0;
        
        vector<int> parents(n);
        for(int i=0;i<n;i++) parents[i]=i;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]= 1+ dp[j];
                    parents[i]=j;
                }
            }
            if(maxi<dp[i]){
                last=i;
                maxi=dp[i];
            }
        }

        while(parents[last]!=last){
            res.push_back(nums[last]);
            last=parents[last];
        }
        res.push_back(nums[last]);
        reverse(res.begin(),res.end());
        return res;
        
    }
};