class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();

        int longest=0;
        int boundary=0;
        int jumps=0;

        for(int i=0;i<n-1;i++){
            longest= max(longest,nums[i]+i); //farthest you can go from this index

            if(i==boundary){
                jumps++;
                boundary=longest;
            }
        }

        return jumps;


        
    }
};