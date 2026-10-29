class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> st(friends.begin(),friends.end());

        vector<int> res;
        for(auto& it:order) if(st.count(it)>0) res.push_back(it);
        return res;
    }
};