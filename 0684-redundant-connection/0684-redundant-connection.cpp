class Solution {
public:
    int findParent(int i,vector<int>& parents){
        if(i==parents[i]) return i;

        return parents[i]=findParent(parents[i],parents);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();

        vector<int> parents(n+1);
        for(int i=1;i<=n;i++){
            parents[i]=i;
        }

        for(auto it:edges){
            int u=it[0];
            int v= it[1];

            int ulp_u=findParent(u,parents);
            int ulp_v=findParent(v,parents);

            if(ulp_u==ulp_v){
                return {u,v};
            }

            parents[ulp_u]=ulp_v;
        }
        return {};
    }
};