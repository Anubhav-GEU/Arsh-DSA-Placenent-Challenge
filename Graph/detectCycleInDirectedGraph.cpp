class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfsRec(vector<int> adj[] , int s , bool vis[] , bool recSt[]){
        vis[s] = true;
        recSt[s] = true;
        
        for(int u : adj[s]){
            if (vis[u] == false && dfsRec(adj,u,vis,recSt))
                return true;
            else if (recSt[u] == true)
                return true;
        }
        recSt[s] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        bool vis[V];
        bool recSt[V];
        
        for (int i=0;i<V;i++){
            vis[i] = recSt[i] = false;
        }
        
        for (int i=0;i<V;i++){
            if (vis[i] == false){
                if (dfsRec(adj,i,vis,recSt) == true)
                    return true;
            }
        }
        return false;
    }
};
