// Simple BFS
// Replace vis array with distance array and compare at each node

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int nodes = adj.size();
        // 1. Initialize a distance matrix for each node and set the distance to be INT_MAX
        vector<int> distance(nodes, INT_MAX);
        
        // 2. Set the source node's distance to be 0
        distance[src] = 0;
        
        // 3. Initialize a queue for BFS with the source/starting node
        queue<int> q;
        q.push(src);
        
        // 4. Start BFS
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(int neighbor:adj[curr]){
                if(distance[curr] + 1 < distance[neighbor]){
                    distance[neighbor] = distance[curr] + 1;
                    q.push(neighbor);
                }
            }
        }
        
        // 5. Validate the distance vector
        for(int i=0;i<nodes;i+=1){
            if(distance[i] == INT_MAX) distance[i] = -1;
        }
        
        return distance;
    }
};
