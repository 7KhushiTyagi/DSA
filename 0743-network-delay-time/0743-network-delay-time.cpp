class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>> graph[n+1];
        for(auto it:times){
            graph[it[0]].push_back({it[1],it[2]});
        }

        
        vector<int> distance(n+1,INT_MAX);
        distance[0]=0;

        priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        distance[k]=0;

        

        while(!pq.empty()){
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            

            for(auto it:graph[node]){
                int cost= it.second;
                int dst= it.first;

                if(cost+time < distance[dst]){
                    distance[dst]= cost+time;
                    pq.push({distance[dst],dst});
                }

            }
        }
        int res=0;
        for(int ele:distance){
            if(ele==INT_MAX) return -1;
            else res= max(res,ele);
        }

        return res;

        
    }
};