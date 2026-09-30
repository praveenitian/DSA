class Solution {
public:
    void dfs(vector<vector<int>>& adj,int u,vector<bool> &vis){
        if(vis[u]) return ;
        vis[u]=true;

        for(auto& v:adj[u]){
            if(!vis[v]){
                dfs(adj,v,vis);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        if(m<n-1) return -1;

        vector<vector<int>> adj(n);

        for(auto& it:connections){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,vis);
                count++;
            }
        }
        return count-1;
    }
};