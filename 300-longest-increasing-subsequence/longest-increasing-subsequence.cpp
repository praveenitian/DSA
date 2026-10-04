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

        // return solve(nums,0,-1);
        vector<int> t(n,1);
        int res=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    t[i]=max(1+t[j],t[i]);
                    res=max(res,t[i]);
                }
            }
        }
        return res;
    }
};