class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for(int num:nums){       //O(N)
            st.insert(num);
        }
        int maxi=0;
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int count=1;
                int x=it;

                while(st.find(x+1)!=st.end()){
                    count++;
                    x++;
                }
                maxi=max(maxi,count);
            }
        }
        return maxi;

        
    }
};