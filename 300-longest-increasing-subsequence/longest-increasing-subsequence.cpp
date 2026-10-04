class Solution {
public:
    int n;
    int dp[2501][2501];

    int solve(vector<int>& nums,int i,int prev){
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];

        int take=0;
        if(prev==-1 || nums[prev]<nums[i]){
            take=1+solve(nums,i+1,i);
        }
        int skip=solve(nums,i+1,prev);

        return dp[i][prev+1]=max(take,skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        
        n=nums.size();
        memset(dp,-1,sizeof(dp));

        return solve(nums,0,-1);
    }
};