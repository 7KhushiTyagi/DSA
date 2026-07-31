class Solution {
public:
    void dfs(int n,vector<vector<int>>& arr,int src,vector<bool>& visited){
        visited[src]=true;

        for(int i=0;i<n;i++){
            if(arr[src][i]==1 && !visited[i]){
                dfs(n,arr,i,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int n= isConnected.size();
        vector<bool> visited(n,false);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(n,isConnected,i,visited);
                count++;
            }
        }
        return count;
        
    }
};