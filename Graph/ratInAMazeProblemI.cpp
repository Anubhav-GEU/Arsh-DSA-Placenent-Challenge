class Solution {
  public:
    vector<string> ans;
    void dfs(int row, int col, int n, vector<vector<int>> mat, string temp) {
        if (row == mat.size()-1 && col == mat.size()-1) {
            ans.push_back(temp);
            return;
        }
        
        if (row<0 || col<0 || row>=mat.size() || col>=mat.size() || mat[row][col] == 0) return;
        if (mat[row][col] == 1)mat[row][col] = 0;
        dfs(row+1,col,n,mat,temp+"D");
        dfs(row-1,col,n,mat,temp+"U");
        dfs(row,col+1,n,mat,temp+"R");
        dfs(row,col-1,n,mat,temp+"L");
        mat[row][col] = 1;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n = mat.size();
        if (mat[0][0] == 0 || mat[n-1][n-1] == 0) return {"-1"};
        dfs(0,0,n,mat,"");
        return ans;
    }
};
