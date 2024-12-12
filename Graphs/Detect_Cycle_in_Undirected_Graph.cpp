// Approach 1 - BFS - Preferred

class Solution {
  public:
  // Helper function to detect cycle
   bool detectCycle(int start, vector<vector<int>>& adj, vector<int>& vis){
      vis[start] = 1; // Mark the starting node as visited
      queue<pair<int,int>> q; // Create a queue to hold a pair-> node and it's parent
      q.push({start, -1}); // Initially, the start will not have a parent so we assume -1
      
      while(!q.empty()){
          int node = q.front().first;
          int parent = q.front().second;
          q.pop();
          // Iterate over the current nodes adj nodes from it's adj list
          for(int adjNode:adj[node]){
	  // If an adjacent node is not visited, mark it as visited and push it to the queue with the current node as parent
              if(!vis[adjNode]){
                  vis[adjNode] = 1;
                  q.push({adjNode, node});
              }
	  // But if an adjacent node is already visited and it is not the parent of the current node,
	  // it means it was visited by a different path -> cycle exists
              else if(parent != adjNode) return true;
          }
      }
    // In case of no cycle, return false
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n,0);
        // Loop to make sure disconnected components are also visited
        for(int i=0;i<n;i+=1){
            if(!vis[i]){
                if(detectCycle(i, adj, vis) == true) return true;
            }
        }
        return false;
    }
};
