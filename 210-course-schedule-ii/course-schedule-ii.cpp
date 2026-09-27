class Solution {
public:

    bool isCycle(vector<vector<int>>& adj,int u,vector<int>& vis){

        vis[u]=1;

        for(auto& v:adj[u]){
            if(vis[v]==0){
                if(isCycle(adj,v,vis)) return true;
            }
            else if(vis[v]==1) return true;
        }
        vis[u]=2;
        return false;
    }

    void dfs(vector<vector<int>>& adj,int start,vector<bool>& vis,vector<int>& res){
        if(vis[start]) return ;
        vis[start]=true;

        for(auto& v:adj[start]){
            if(!vis[v]){
                dfs(adj,v,vis,res);
            }
        }
        res.push_back(start);

    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        
        vector<vector<int>> adj(numCourses);

        for(auto& it:pre){
            int u=it[1];
            int v=it[0];

            adj[u].push_back(v);
        }

        vector<bool> vis(numCourses,false);
        vector<int> res;

        vector<int> viss(numCourses,0);
        bool cycle=false;

        for(int i=0;i<numCourses;i++){
            if(!viss[i]){
                if(isCycle(adj,i,viss)) cycle=true;
            }
        }

        if(cycle) return {};

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                dfs(adj,i,vis,res);
            }
        }

        reverse(res.begin(),res.end());
        return res;
    }
};