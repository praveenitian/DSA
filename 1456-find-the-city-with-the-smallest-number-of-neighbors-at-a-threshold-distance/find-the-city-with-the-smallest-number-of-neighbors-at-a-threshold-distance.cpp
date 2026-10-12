class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int th) {
        
        vector<vector<int>> grid(n,vector<int>(n,1e9));

        for(auto& it:edges){
            int i=it[0];
            int j=it[1];
            int val=it[2];

            grid[i][j]=grid[j][i]=val;
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
        int ans=0;

        int mx=INT_MAX;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]<=th) count++;
            }
            mx=min(mx,count);
            if(count<=mx){
                ans=i;
            }   
        }

        return ans;
    }
};