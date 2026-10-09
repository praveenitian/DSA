class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto& it:times){
            int u=it[0];
            int v=it[1];
            int w=it[2];

            adj[u].push_back({v,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<int> res(n+1,INT_MAX);

        res[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            int node=pq.top().second;
            int d   =pq.top().first;
            pq.pop();

            for(auto& it:adj[node]){
                int adjnode=it.first;
                int t=it.second;

                if(d+t<res[adjnode]){
                    res[adjnode]=d+t;
                    pq.push({d+t,adjnode});
                }
            }

        }

        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,res[i]);
        }
        
        if(ans==INT_MAX) return -1;
        return ans;
    }
};