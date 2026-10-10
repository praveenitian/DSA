class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1])
            return -1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int count = 0;

        while (!q.empty()) {
            int N = q.size();

            while (N--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                if(r==n-1 && c==n-1) return count+1;

                vector<int> dirx = {-1, -1, -1, 0, 1, 1, 1, 0};
                vector<int> diry = {-1, 0, 1, 1, 1, 0, -1, -1};

                for (int i = 0; i < 8; i++) {
                    int row = r + dirx[i];
                    int col = c + diry[i];

                    if (row >= 0 && row < n && col >= 0 && col < n &&
                        grid[row][col] == 0) {
                        grid[row][col] = 1;
                        q.push({row, col});
                    }
                }
            }
            count++;
        }
        return -1;
    }
};