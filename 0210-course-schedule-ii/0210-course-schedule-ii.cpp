class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V= numCourses;
        vector<int> graph[V];

        for(auto &it:prerequisites){
            graph[it[1]].push_back(it[0]);
        }

        vector<int> indegree(V,0);

        for(int i=0;i<V;i++){
            for(auto &ele: graph[i]){
                indegree[ele]++;
            }
        }

        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> res;

        while(!q.empty()){
            int ele=q.front();
            q.pop();

            res.push_back(ele);

            for(auto neighbour:graph[ele]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        if(res.size()!=V){
            return {};
        }
        return res;
        
    }
};