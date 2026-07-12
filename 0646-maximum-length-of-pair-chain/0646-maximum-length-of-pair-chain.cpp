struct Pair{
    int start;
    int end;

};

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int length=0;
        int n=pairs.size();

        vector<Pair> nums;
        for(auto it:pairs){
            nums.push_back({it[0],it[1]});
        }

        sort(nums.begin(),nums.end(),[](Pair &p1,Pair &p2){
             return p1.end<p2.end;
        });

        int last=INT_MIN;

        for(auto it:nums){
            if(it.start>last){
                length++;
                last=it.end;
            }
        }
        return length;

        
        
    }
};