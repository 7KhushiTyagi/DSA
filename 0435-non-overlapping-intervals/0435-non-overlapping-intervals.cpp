class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int total= intervals.size();

        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
            if(a[1]==b[1]) return a[0]<b[0];
            return a[1]<b[1];
        });

        int last= intervals[0][1];
        int count=1;

        for(int i=1;i<total;i++){
            if(intervals[i][0]>=last){
                count++;
                last= intervals[i][1];
            }
        }

        return total-count;
        
        
    }
};