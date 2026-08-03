class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int total=0;
        for(int num:nums){
            total+=num;
        }

        int left_sum=0;
        for(int i=0;i<nums.size();i++){
            
            int right_sum= total-nums[i]-left_sum;

            if(left_sum==right_sum){
                return i;
            }
            left_sum+=nums[i];
        }

        return -1;
        
    }
};