class Solution {
public:
    int n;

    int solve(vector<int>& nums,int i,int n,vector<int>& dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

        return dp[i]=max(solve(nums,i+1,n,dp),nums[i]+solve(nums,i+2,n,dp));
    }

    int rob(vector<int>& nums) {
        n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);

        return max(solve(nums,0,n-1,dp1),solve(nums,1,n,dp2));
    }
};