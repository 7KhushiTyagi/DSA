class Solution {
public:
    void dfs(int src,vector<vector<int>>& isConnected,vector<bool>& visited,int n){
        visited[src]=true;

        for(int i=0;i<n;i++){
            if(!visited[i] && isConnected[src][i]==1){
                dfs(i,isConnected,visited,n);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int count=0;

        vector<bool> visited(n+1,false);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,isConnected,visited,n);
                count++;
            }
        }
        return count;
        
    }
};