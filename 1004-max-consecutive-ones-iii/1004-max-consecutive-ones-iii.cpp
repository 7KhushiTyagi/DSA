class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int count=0;
        int n= nums.size();
        int right=0;
        int left=0;
        int len=0;

        while(right<n){
            if(nums[right]==0){
                count++;
            }

            while(count>k){
                if
                (nums[left]==0) count--;
              left++;
            }

            len=max(len,right-left+1);
            right++;
        }
        return len;
    }
};