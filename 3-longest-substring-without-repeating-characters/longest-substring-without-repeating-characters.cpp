class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();

        vector<int> hash(256,-1);

        int l=0,r=0;
        int mx=0;

        while(r<n){
            
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l) l=hash[s[r]]+1;
            }

            int curr=r-l+1;
            mx=max(curr,mx);

            hash[s[r]]=r;
            r++;
        }
        return mx;
    }
};