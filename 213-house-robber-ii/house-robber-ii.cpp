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
        // vector<int> dp1(n,-1);
        // vector<int> dp2(n,-1);

        // return max(solve(nums,0,n-1,dp1),solve(nums,1,n,dp2));

        vector<int> dp1(n+1,0);
        vector<int> dp2(n+1,0);

        dp1[0]=0,dp1[1]=nums[0];

        for(int i=2;i<n;i++){
            dp1[i]=max(nums[i-1]+dp1[i-2],dp1[i-1]);
        }

        dp2[0]=0,dp2[1]=0;
        for(int i=2;i<=n;i++){
            dp2[i]=max(nums[i-1]+dp2[i-2],dp2[i-1]);
        }

        return max(dp1[n-1],dp2[n]);
    }
};