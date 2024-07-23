class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        if (row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || vis[row][col] == 1 || grid[row][col] == '0') {
            return;
        }
        vis[row][col] = 1;
        dfs(row+1,col,vis,grid);
        dfs(row-1,col,vis,grid);
        dfs(row,col+1,vis,grid);
        dfs(row,col-1,vis,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    dfs(i,j,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
};
