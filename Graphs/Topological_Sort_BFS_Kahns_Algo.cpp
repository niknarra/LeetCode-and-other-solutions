class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int nodes = adj.size();
        vector<int> degrees(nodes, 0);
        
        // 1. Get the indegrees of all the nodes
        for(int i=0;i<nodes;i+=1){
            for(int neighbor:adj[i]){
                degrees[neighbor] += 1;
            }
        }
        
        // 2. Start with pushing the nodes with 0 indegree to the stack
        stack<int> st;
        for(int i=0;i<nodes;i+=1){
            if(degrees[i] == 0) st.push(i);
        }
        
        // 3. Now as long as there is a node in the stack, do BFS and push to ans vector
        vector<int> topo;
        
        while(!st.empty()){
            int curr = st.top();
            st.pop();
            
            // As we are processing the curr node, we can remove the degree of it's neighbors
            // i.e., we are removing the edge from curr node to it's neighbor, so neighbor's indegree will be --
            // And if it is 0, we can push it to stack
            for(int neighbor:adj[curr]){
                degrees[neighbor] -= 1;
                if(degrees[neighbor] == 0) st.push(neighbor);
            }
            // Push to ans vector after processing
            topo.push_back(curr);
        }
        return topo;
    }
};
