class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for(int num:nums){
            st.insert(num);
        }

        int ans=0;

        for(int it:st){
            if(st.find(it-1)==st.end()){
                int count=1;
                int x=it;

                while(st.find(x+1)!=st.end()){
                    count++;
                    x++;
                }

                ans=max(ans,count);
            }
        }

        return ans;
        
    }
};