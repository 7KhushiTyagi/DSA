class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>& colored,int src,int prev){
        colored[src] = (prev==0) ? 1 : 0;

        for(int ele:graph[src]){
            if(colored[ele]==-1){
                if(!dfs(graph,colored,ele,colored[src])){
                    return false;
                }
            }else{
                if(colored[ele]==colored[src]){
                    return false;
                }
            }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {

        int V= graph.size();
        vector<int> colored(V,-1);

        for(int i=0;i<V;i++){
            if(colored[i]==-1){
               if(!dfs(graph,colored,i,0)){
                return false;
               }
            }
        }
        return true;
        
    }
};