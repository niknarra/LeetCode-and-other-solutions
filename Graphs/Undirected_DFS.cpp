class Solution {
  public:
  // Recursive helper function
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& dfs_list){
        vis[node] = 1;
        dfs_list.push_back(node);
        
        for(int neighbor:adj[node]){
            if(!vis[neighbor]){
                dfs(neighbor, adj, vis, dfs_list);
            }
        }
        
    }
 
   // Main Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        int nodes = adj.size();
        vector<int> vis(nodes, 0);
        vector<int> dfs_list;
        
        dfs(0, adj, vis, dfs_list);
        
        return dfs_list;
    }
};
