class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<3) return 0;
        sort(nums.begin(),nums.end());
        int sum= nums[0]+nums[1]+nums[2];

        for(int i=0;i<n-1;i++){
            int left= i+1;
            int right= n-1;

            while(left<right){
                int curr = nums[i]+nums[left]+nums[right];

                if(curr==target){
                    return curr;
                }
                if(abs(target-curr) < abs(target-sum)){
                   sum=curr;
                }
                if(curr>target){
                    right--;
                }else{
                    left++;
                }
            }

        }
        return sum;
        
    }
};