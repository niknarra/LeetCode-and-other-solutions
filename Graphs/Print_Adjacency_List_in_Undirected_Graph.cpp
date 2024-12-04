vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        vector<vector<int>> adj;
            for(auto it:edges){
                adj[it.first].push_back(it.second);
                adj[it.second].push_back(it.first);
            }
   return adj;
}

// TC: O(V + n) -> V for creation of the empty adj list, n for traversal
// SC: O(V + n)
