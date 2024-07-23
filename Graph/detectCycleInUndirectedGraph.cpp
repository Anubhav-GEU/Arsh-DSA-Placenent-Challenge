class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfsRec(vector<int> adj[] , int s , bool vis[], int parent){
        vis[s] = true;
        for (int u : adj[s]){
            if (vis[u] == false){
                if (dfsRec(adj,u,vis,s) == true){
                    return true;
                }
            }
            else if (u != parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool vis[V];
        for (int i=0;i<V;i++){
            vis[i] = false;
        }
        
        for (int i=0;i<V;i++){
            if (vis[i] == false){
                if (dfsRec(adj,i,vis,-1) == true){
                    return true;
                }
            }
        }
        return false;
    }
};
