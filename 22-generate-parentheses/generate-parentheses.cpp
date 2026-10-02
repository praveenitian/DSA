class Solution {
public:
    set<string> res;

    bool isValid(string s){
        stack<int> st;
        if(s[0]==')') return false;
        
        for(auto& it:s){
            if(!st.empty() && it==')'){
                if(st.top()==it) return false;
                else st.pop();
            }
            else st.push(it);
        }
        if(st.empty()) return true;
        return false;
    }

    void solve(string curr,int n){
        if(curr.size()==2*n){
            if(isValid(curr)) res.insert(curr);
            return ;
        }

        curr.push_back('(');
        solve(curr,n);
        curr.pop_back();
        curr.push_back(')');
        solve(curr,n);
        curr.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        solve("",n);
        vector<string> ans;
        for(auto& it:res) ans.push_back(it);
        return ans;
    }
};