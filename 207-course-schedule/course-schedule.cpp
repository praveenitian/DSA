class Solution {
public:

    bool dfs(vector<vector<int>>& adj,int u,vector<int>& vis){
        vis[u]=1;

        for(auto& v:adj[u]){
            if(vis[v]==0){
                if(dfs(adj,v,vis)) return true;
            }
            else if(vis[v]==1) return true;
        }
        vis[u]=2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();

        vector<vector<int>> adj(numCourses);
        for(auto& it:prerequisites){
            int v=it[0];
            int u=it[1];

            adj[u].push_back(v);
        }
        vector<int> vis(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(adj,i,vis)) return false;
            }
        }
        return true;
    }
};