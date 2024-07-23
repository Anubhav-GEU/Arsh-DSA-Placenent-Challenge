class Solution {
public:
    void dfs(int row, int col, int same, int color, vector<vector<int>>& image) {
        if (row<0 || col<0 || row>=image.size() || col>=image[0].size() || image[row][col] == color || image[row][col] != same) {
            return;
        }
        image[row][col] = color;
        dfs(row+1,col,same,color,image);
        dfs(row-1,col,same,color,image);
        dfs(row,col+1,same,color,image);
        dfs(row,col-1,same,color,image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int sameColour = image[sr][sc];
        dfs(sr,sc,sameColour,color,image);
        return image;
    }
};
