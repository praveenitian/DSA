class Solution {
public:
    bool dfs(vector<vector<int>> &adj,int node,vector<int>& color,int currCol){
        color[node]=currCol;

        for(auto& v:adj[node]){
            if(color[v]==currCol){
                return false;
            }
            else if(color[v]==-1){
                int newCol=1-currCol;
                if(dfs(adj,v,color,newCol)==false) return false;
            }
        }
        return true;
    }

    bool bfs(vector<vector<int>>& adj,int start,vector<int>& color,int currCol){
        queue<int> q;
        q.push(start);
        color[start]=currCol;

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(auto& v:adj[u]){
                if(color[v]==color[u]) return false;
                else if(color[v]==-1){
                    color[v]=1-color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int> color(n,-1);

        // for(int i=0;i<n;i++){
        //     if(color[i]==-1){
        //         if(dfs(graph,i,color,0)==false) return false;
        //     }
        // }
        // return true;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(bfs(graph,i,color,0)==false) return false;
            }
        }
        return true;
        
    }
};