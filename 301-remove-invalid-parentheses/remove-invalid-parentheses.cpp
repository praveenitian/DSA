class Solution {
public:
    set<string> ans;
    int maxlen=0;
    void solve(string &s,int count,int i,string &curr){
        int n=s.size();
        if(count<0) return ;
        if(i==n){
            if(count==0){
                if(curr.size()>maxlen){
                    maxlen=curr.size();
                    ans.clear();
                }
                if(maxlen==curr.size()) ans.insert(curr);
            }
            
            return ;
        }

        if(s[i]!='(' && s[i]!=')'){
            curr.push_back(s[i]);
            solve(s,count,i+1,curr);
            curr.pop_back();
            return ;
        }

        curr.push_back(s[i]);
        if(s[i]=='(') count++;
        else count--;
        solve(s,count,i+1,curr);
        if(s[i]=='(') count--;
        else count++;
        curr.pop_back();

        solve(s,count,i+1,curr);

    }

    vector<string> removeInvalidParentheses(string s) {
        int n=s.size();
        string curr="";
        solve(s,0,0,curr);
        vector<string> out;
        
        for(auto& it:ans) out.push_back(it);
        return out;
    }
};