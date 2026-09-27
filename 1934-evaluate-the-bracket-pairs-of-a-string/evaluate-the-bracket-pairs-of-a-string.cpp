class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=s.size();

        unordered_map<string,string> mp;
        for(auto& it:knowledge){
            string key=it[0];
            string value=it[1];
            mp[key]=value;
        }

        int i=0;
        string res="";
        while(i<n){

            if(s[i]=='('){
                i++;
                string key="";
                while(s[i]!=')'){
                    key+=s[i];
                    i++;
                }
                if(mp.count(key)==0){
                     res+="?";
                }
                else res+=mp[key];
                i++;
            }
            else{
                res+=s[i];
                i++;
            }
            
        }
        return res;
    }
};