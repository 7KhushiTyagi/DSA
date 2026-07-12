class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;

        vector<int> graph[V];
        vector<int> indegree(V);
        for(auto ele:prerequisites){
            graph[ele[1]].push_back(ele[0]);
            indegree[ele[0]]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> res;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            res.push_back(node);

            for(int neighbour: graph[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }

        return res.size()==V;



        
    }
};