class Solution {
public:
    int m,n;
    int orangesRotting(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        int count=0;

        while(!q.empty()){
            int sz=q.size();

            while(sz--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();

                vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};

                for(int i=0;i<4;i++){
                    int row=r+dir[i][0];
                    int col=c+dir[i][1];

                    if(row>=0 && col>=0 && row<m && col<n && grid[row][col]!=2 && grid[row][col]!=0){
                        grid[row][col]=2;
                        q.push({row,col});
                    }
                }

            }
            count++;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return (count==0)?0:count-1;
    }
};