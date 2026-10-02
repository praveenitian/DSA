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

    bool isCycle(vector<vector<int>> &adj,int i,int n){
        vector<int> vis(n,0);

        return dfs(adj,i,vis);
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> res;

        for(int i=0;i<n;i++){
            if(isCycle(adj,i,n)==false) res.push_back(i);
        }
        // sort(res.begin(),res.end());
        return res;
    }   
};