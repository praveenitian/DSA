class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find (int x) {
        if (x == parent[x]) 
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++) parent[i]=i;

        vector<vector<int>> edges;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int u=i;
                int v=j;
                int w=(abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]));

                edges.push_back({u,v,w});
            }
        }

        sort(edges.begin(),edges.end(),[](vector<int>& v1,vector<int>& v2){
            return v1[2]<v2[2];
        });
        int sum=0;

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];

            int p1=find(u);
            int p2=find(v);

            if(p1!=p2){
                Union(u,v);
                sum+=w;
            }
        }
        return sum;
    }
};