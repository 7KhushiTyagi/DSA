class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 0-> 0 to low-1
        // 1-> low to mid-1
        //unsorted -> mid to high-1
        // 2-> high to n-1

        int low=0;
        int mid=0;
        int high= nums.size()-1;

        for(int num:nums){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        
    }
};