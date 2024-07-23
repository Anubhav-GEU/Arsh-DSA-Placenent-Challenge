class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> ans;
    void dfs(int src, vector<int>& vis, vector<int> adj[]) {
        vis[src] = 1;
        ans.push_back(src);
        for (auto& x:adj[src]) {
            if (!vis[x]) {
                vis[x] = 1;
                dfs(x,vis,adj);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        dfs(0,vis,adj);
        return ans;
    }
};
