class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();

        stack<int> st;
        st.push(s[0]);
        int i=1;
        while(i<n){
            
            if(s[i]==')'){
                i++;
                string str="";
                while(st.top()!='('){
                    str+=st.top();
                    st.pop();
                }
                st.pop();
                for(auto& it:str) st.push(it);
            }
            else{
                st.push(s[i]);
                i++;
            }
        }

        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;

    }
};