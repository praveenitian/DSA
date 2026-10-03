class Solution {
public:
    int solve(vector<int>& nums,int i,vector<int>& dp){
        int n=nums.size();
        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];

        return dp[i]= max(nums[i]+solve(nums,i+2,dp),solve(nums,i+1,dp));
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=nums[0];

        for(int i=2;i<=n;i++){
            dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
        }
        return dp[n];

        // return solve(nums,0,dp);
    }
};