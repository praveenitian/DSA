class Solution {
public:

    bool isBipartite(vector<vector<int>> &adj,int u,vector<int>& color,int currCol){
        color[u]=currCol;

        for(auto& v:adj[u]){
            if(color[v]==currCol) return false;
            else if(color[v]==-1){
                if(isBipartite(adj,v,color,1-currCol)==false) return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& grid) {
        
        vector<vector<int>> adj(n+1);

        for(auto& it:grid){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n+1,-1);

        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(isBipartite(adj,i,color,0)==false) return false;
            }
        }
        return true;
    }
};