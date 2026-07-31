class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> g(n);
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                g[neighbor].push_back(i);
                indegree[i]++;
            }
        }

        vector<int> res;
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int ele = q.front();
            q.pop();
            res.push_back(ele);

            for (int it : g[ele]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};