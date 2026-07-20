class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> graph(n);
        vector<int> indegree(n,0);

        for(auto& it:prerequisites){
            graph[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int> q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> res;
        while(!q.empty()){
            int ele=q.front();
            q.pop();

            res.push_back(ele);

            for(int it:graph[ele]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        return res.size()==n;


        
    }
};