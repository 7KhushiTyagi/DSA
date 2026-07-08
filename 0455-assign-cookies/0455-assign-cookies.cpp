class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m=g.size();
        int n=s.size();

        if(m==0 || n==0) return 0;

        int left=0;
        int right=0;
        int count=0;

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        while(left<m && right<n){
            if(g[left]<=s[right]){
                count++;
                left++;
            }
            right++;
        }
        return count;
    }
};