class Solution {
public:
    // BFS and DIJKSTRA Both 
    typedef pair<int,pair<int,int>> P;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] || grid[n - 1][n - 1])
            return -1;
        
        vector<vector<int>> dis(n,vector<int> (n,INT_MAX));
        dis[0][0]=1;

        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({1,{0,0}});

        while(!pq.empty()){
            int d=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();

            if(r==n-1 && c==n-1) return dis[r][c];


            vector<int> dirx={-1, -1, -1, 0, 0, 1, 1, 1};
            vector<int> diry={-1, 0, 1, -1, 1, -1, 0, 1};

            for(int i=0;i<8;i++){
                int row=r+dirx[i];
                int col=c+diry[i];

                int dist=d+1;

                if(row>=0 && col>=0 && row<n && col<n && grid[row][col]==0){
                    if(dist<dis[row][col]){
                        dis[row][col]=dist;
                        grid[row][col]=1;
                        pq.push({dist,{row,col}});
                    } 
                }
            }

        }
        return -1;
    }
};