class Solution {
  public:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, stack<int>& st, int start){
        vis[start] = 1;
        
        for(int neighbor:adj[start]){
            if(!vis[neighbor]){
                dfs(adj, vis, st, neighbor);
            }
        }
        st.push(start);
    }
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        vector<int> ans;
        int nodes = adj.size();
        vector<int> vis(nodes, 0);
        stack<int> st;
        
        for(int i=0;i<nodes;i+=1){
            if(vis[i] == 0){
                dfs(adj, vis, st, i);
            }
        }
        
        while(!st.empty()){
            int curr = st.top();
            st.pop();
            ans.push_back(curr);
        }
        
        return ans;
    }
};
