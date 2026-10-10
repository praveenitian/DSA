class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int,double>>> adj(n);

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double p=succProb[i];

            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }

        priority_queue<pair<double,int>,vector<pair<double,int>>> pq;

        vector<double> prob(n,0);
        prob[start]=1;
        pq.push({1,start});

        while(!pq.empty()){
            double p=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto& it:adj[node]){
                int adjnode=it.first;
                double pro=it.second;

                if(pro*p>prob[adjnode]){
                    prob[adjnode]=pro*p;
                    pq.push({pro*p,adjnode});
                }
            }

        }
        return prob[end];
    }
};