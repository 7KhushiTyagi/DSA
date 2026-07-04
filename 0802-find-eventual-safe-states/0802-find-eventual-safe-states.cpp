class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<vector<int>> Graph(V);
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(int ele:graph[i]){
                Graph[ele].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){q.push(i);}
        }
        vector<int> ans;

        while(!q.empty()){
            int ele=q.front();
            q.pop();
            ans.push_back(ele);

            for(int neighbour:Graph[ele]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

        
        
    }
};