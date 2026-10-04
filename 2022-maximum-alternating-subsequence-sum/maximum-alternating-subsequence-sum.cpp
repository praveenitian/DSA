class Solution {
public:
    int n;

    long long solve(vector<int>& nums,int i,int flag,vector<vector<long long>>& dp){

        if(i==n) return 0;

        if(dp[i][flag]!=-1) return dp[i][flag];

        long long value=(flag)?nums[i]:-nums[i];

        long long take=value+solve(nums,i+1,1-flag,dp);
        long long skip=solve(nums,i+1,flag,dp);

        return dp[i][flag]=max(take,skip);
    }


    long long maxAlternatingSum(vector<int>& nums) {
        n=nums.size();
        // vector<vector<long long>> dp(n+1,vector<long long>(3,-1));
        // return solve(nums,0,1,dp);

        vector<vector<long long>> dp(n+1,vector<long long>(2,0));

        for(int i=1;i<=n;i++){
            dp[i][0]=max(dp[i-1][1]-nums[i-1],dp[i-1][0]);
            dp[i][1]=max(dp[i-1][0]+nums[i-1],dp[i-1][1]);
        }

        return max(dp[n][0],dp[n][1]);
    }
};