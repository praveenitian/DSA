class Solution {
public:
    typedef pair<int,pair<int,int>> P;

    int minimumEffortPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> res(m,vector<int> (n,1e9));
        priority_queue<P,vector<P>,greater<P>> pq;

        res[0][0]=0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int diff=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();

            vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};

            for(int i=0;i<4;i++){
                int row=r+dir[i][0];
                int col=c+dir[i][1];
                

                if(row>=0 && col>=0 && row<m && col<n ){
                    int d=max(diff,abs(grid[row][col]-grid[r][c]));
                    if(res[row][col]>d){
                        res[row][col]=d;
                        pq.push({d,{row,col}});
                    }
                }
            }
        }
        return res[m-1][n-1];

    }
};