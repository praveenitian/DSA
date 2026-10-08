class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();

        string res;
        int count=0;

        for(int i=0;i<n;i++){
            if(count!=0 && s[i]=='(') res.push_back(s[i]);
            if(count!=1 && s[i]==')') res.push_back(s[i]);

            if(s[i]=='(') count++;
            else count--;

        }
    
        return res;
    }
};