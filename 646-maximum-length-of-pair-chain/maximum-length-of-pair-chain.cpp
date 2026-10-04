class Solution {
public:
    int dp[1001][1001];

    int solve(vector<vector<int>>& pairs,int i,int prev){
        int n=pairs.size();
        if(i==n) return 0;

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];

        int take=0;
        if(prev==-1 || pairs[prev][1]<pairs[i][0]){
            take=1+solve(pairs,i+1,i);
        }
        int skip=solve(pairs,i+1,prev);
        return dp[i][prev+1]= max(take,skip);

    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();

        sort(pairs.begin(),pairs.end());
        // memset(dp,-1,sizeof(dp));
        // return solve(pairs,0,-1);

        vector<int> t(n,1);
        int res=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[i][0]>pairs[j][1]){
                    t[i]=max(t[i],1+t[j]);
                    res=max(res,t[i]);
                }
            }
        }
        return res;
    }
};