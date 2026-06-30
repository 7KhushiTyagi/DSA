class Solution {
public:
    bool possible(int limit,int days,vector<int> nums){
        int count=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>limit){
                count++;
                sum=0;
                if(count>days) return false;
            }
            sum+=nums[i];
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low= *max_element(weights.begin(),weights.end());
        int high= accumulate(weights.begin(),weights.end(),0);

        while(high>=low){
            int mid = low+(high-low)/2;

            if(possible(mid,days,weights)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
        
    }
};