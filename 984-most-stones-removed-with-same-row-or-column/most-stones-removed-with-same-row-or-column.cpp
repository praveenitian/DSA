class Solution {
public:
    int n;

    void dfs(vector<vector<int>>& stones,unordered_set<int>& vis,int j){
        vis.insert(j);

        for(int i=0;i<n;i++){
            if(vis.count(i)==0){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                    dfs(stones,vis,i);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        n=stones.size();
        int count=0;

        unordered_set<int> vis;

        for(int i=0;i<n;i++){
            if(vis.count(i)==0){
                dfs(stones,vis,i);
                count++; 
            }
        }
        return n-count;
    }
};