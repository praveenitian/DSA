class Solution {
public:
    int M=1e9+7;
    vector<vector<int>> adj={
        {4,6},
        {6,8},
        {7,9},
        {4,8},
        {0,3,9},
        {},
        {0,1,7},
        {2,6},
        {1,3},
        {2,4}
    };

    int dp[5001][10];
    int solve(int n,int i){
        if(dp[n][i]!=-1) return dp[n][i];
        if(n==0) return 1;
        int count=0;
        for(auto& it:adj[i]){
            count=(count+solve(n-1,it))%M;
        }
        return dp[n][i]=count;
    }

    int knightDialer(int n) {
        int count=0;
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<=9;i++){
            count=(count+solve(n-1,i))%M;
        }
        return count;
    }
};