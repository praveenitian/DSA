class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<pair<int,int>> arr;

        for(int i=0;i<m;i++){
            int count=0;
            for(int j=0;j<n;j++) if(mat[i][j]==1) count++;
            arr.push_back({count,i});
        }
        sort(arr.begin(),arr.end());
        vector<int> res;
        for(int i=0;i<k;i++) res.push_back(arr[i].second);
        return res;

    }
};