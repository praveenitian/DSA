class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& grid, int src, int des, int k) {
        int m=grid.size();

        vector<vector<pair<int,int>>> adj(n);

        for(auto& it:grid){
            int u=it[0];
            int v=it[1];
            int t=it[2];

            adj[u].push_back({v,t});
        }

        queue<pair<int,int>> pq;
        vector<int> res(n,INT_MAX);
        res[src]=0;
        pq.push({0,src});

        while(!pq.empty() && k>=0){
            int N=pq.size();

            while(N--){
                int node=pq.front().second;
                int t   =pq.front().first;
                pq.pop();

                for(auto& it:adj[node]){
                    int adjnode=it.first;
                    int time = it.second;

                    if(t+time<res[adjnode]){
                        res[adjnode]=t+time;
                        pq.push({t+time,adjnode});
                    }
                }
            }
            k--;
            
        }
        return (res[des]==INT_MAX)?-1:res[des];
    }
};