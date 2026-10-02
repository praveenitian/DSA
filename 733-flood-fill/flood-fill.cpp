class Solution {
public:
    int check;
    void dfs(vector<vector<int>>& grid,int i,int j,int color){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==color || grid[i][j]!=check){
            return ;
        }
        grid[i][j]=color;

        dfs(grid,i+1,j,color);
        dfs(grid,i-1,j,color);
        dfs(grid,i,j+1,color);
        dfs(grid,i,j-1,color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        check=image[sr][sc];

        dfs(image,sr,sc,color);

        return image;
    }
};