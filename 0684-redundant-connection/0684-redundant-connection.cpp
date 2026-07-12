class Solution {
public:
    int findParent(int i,vector<int>& parent){
        if(i==parent[i]){
            return i;
        }

        return findParent(parent[i],parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        
        vector<int> parent(n+1,0);

        for(int i=1;i<=n;i++){
            parent[i]=i;
        }

        for(auto ele:edges){
            int u= ele[0];
            int v= ele[1];

            int ulp_u=findParent(u,parent);
            int ulp_v= findParent(v,parent);

            if(ulp_u==ulp_v) return {u,v};

            parent[ulp_v]=ulp_u;
        }
        return {};
        
    }
};