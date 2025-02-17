// Bipartite Graph - A graph that can be divided into a disjoint set X and Y where every node in X is connected to node in Y
// And also no edges exist between nodes of same set
// Or, a graph that can be colored with 2 colors where the adjacent nodes don't share the same color

class Solution {
  public:
    bool isBipartite(vector<vector<int>>& adj) {
        int nodes = adj.size();
        vector<int> color(nodes, -1);
        // Initially push the starting node as 0 and color it
        queue<int> q;
        q.push(0);
        color[0] = 0;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            // For each neighbor of the current node,
            for(int neighbor:adj[curr]){
		// Check if it is not colored, then color it in the opposite color and push to queue
                if(color[neighbor] == -1){
                    color[neighbor] = !color[curr];
                    q.push(neighbor);
                }
		// In case it is colored, then return false if the same color
		// Essentially, there is a cycle and some other node has colored it already
                else if(color[neighbor] == color[curr]) return false;
            }
        }
        return true;
    }
};

// A bipartite grpah will have a cycle and the length of the cycle must be even.
