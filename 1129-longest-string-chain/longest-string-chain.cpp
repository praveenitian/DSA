class Solution {
public:
    int dp[1001][1001];

    bool check(string &a,string &b){
       int i=0,j=0;
       while(i<a.size() && j<b.size()){
            if(a[i]==b[j]) j++;
            i++;
       }
       return j==b.size();
    }

    int solve(vector<string>& words,int i,int prev){
        int n=words.size();
        if(i==n) return 0;

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];

        int take=0;
        if(prev==-1 ||(words[i].size()==words[prev].size()+1 && check(words[i],words[prev]))){
            take=1+solve(words,i+1,i);
        }
        int skip=solve(words,i+1,prev);
        return dp[i][prev+1]=max(take,skip);
    }

    static bool myfun(string &s1,string &s2){
            return s1.size()<s2.size();
        }

    int longestStrChain(vector<string>& words) {
        int n=words.size();

    

        // sort(words.begin(),words.end(),[](string s1,string s2){
        //     return s1.size()<s2.size();
        // });
        sort(words.begin(),words.end(),myfun);

        memset(dp,-1,sizeof(dp));

        return solve(words,0,-1);
    }
};