class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int n=g.size();
        int m=s.size();

        if(n==0 || m==0) return 0;
        int left=0;int right=0;
        int count=0;

        while(left<n && right<m){
             if(g[left]<=s[right]){
                count++;
                left++;
             }
             right++;
        }

        return count;
        
    }
};