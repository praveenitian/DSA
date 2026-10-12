class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        
        vector<vector<int>> grid(n,vector<int>(n,1e9));

        for(auto& it:pre){
            int i=it[0];
            int j=it[1];
            int val=1;

            grid[i][j]=val;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) grid[i][j]=0;
            }
        }

        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    grid[i][j]=min(grid[i][j],grid[i][via]+grid[via][j]);
                }
            }
        }

        vector<bool> ans(q.size(),false);

        for(int i=0;i<q.size();i++){
            int a=q[i][0];
            int b=q[i][1];

            if(grid[a][b]!=1e9) ans[i]=true;
        }
        return ans;
    }
};