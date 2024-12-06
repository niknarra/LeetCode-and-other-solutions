// This works for an undirected connected graph
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

// To make it handle connected and unconnected graphs

#include <vector>
using namespace std;

void dfs(int start, const vector<vector<int>>& adj, vector<int>& vis, vector<int>& dfs_list) {
    vis[start] = 1;
    dfs_list.push_back(start);

    for (int neighbor : adj[start]) {
        if (!vis[neighbor]) {
            dfs(neighbor, adj, vis, dfs_list);
        }
    }
}

vector<int> dfsOfGraph(int n, const vector<vector<int>>& adj) {
    vector<int> vis(n, 0); // Assuming 0-based indexing
    vector<int> dfs_list;
    // We loop through all of the nodes to make sure they are visited
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i, adj, vis, dfs_list);
        }
    }

    return dfs_list;
}

