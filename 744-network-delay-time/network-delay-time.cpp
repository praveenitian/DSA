class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<int> dis(n+1,INT_MAX);
        dis[k]=0;
        
        for(int i=1;i<n;i++){

            for(auto& it:times){
                int u=it[0];
                int v=it[1];
                int w=it[2];

                if(dis[u]!=INT_MAX && dis[u]+w<dis[v]){
                    dis[v]=dis[u]+w;
                }
            }
        }

        int ans=0;
        for(int i=1;i<=n;i++) ans=max(ans,dis[i]);
        return (ans==INT_MAX)?-1:ans;
    }
};