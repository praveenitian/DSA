class Solution {
public:
    int m,n;
    int dp[501][501][4];
    int M=1e9+7;

    int solve(vector<vector<int>>& grid,int i,int j,int dir){
        if(i<0 || j<0 || i>=m || j>=n) return 0;
 
        if(i==m-1 && j==n-1) return 1;

        if(dp[i][j][dir+1]!=-1) return dp[i][j][dir+1];

        int right=0;
        int down=0;

        if(grid[i][j]==1){
            if(dir==0){
                down=solve(grid,i+1,j,1);
            }
            else if(dir==1){
                right=solve(grid,i,j+1,0);
            }
        }
        else {
            right=solve(grid,i,j+1,0);
            down=solve(grid,i+1,j,1);
        }
        return dp[i][j][dir+1]=(right+down)%M;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(dp,-1,sizeof(dp));

        return solve(grid,0,0,-1);
    }
};