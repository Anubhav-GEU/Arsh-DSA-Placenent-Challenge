class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
        q.push(0);
        vector<int> ans;
        vector<int> vis(V,0);
        vis[0] = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto top = q.front();
                q.pop();
                ans.push_back(top);
                for (auto& x: adj[top]) {
                    if (!vis[x]) {
                        q.push(x);
                        vis[x] = 1;
                    }
                }
            }
        }
        return ans;
    }
};
