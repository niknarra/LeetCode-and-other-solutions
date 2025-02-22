class Solution {
public:
    bool bfs(vector<vector<int>>& graph, vector<int>& color, int start){
        queue<int> q;
        color[start] = 0;
        q.push(start);

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int neighbor:graph[curr]){
                if(color[neighbor] == -1){
                    color[neighbor] = !color[curr];
                    q.push(neighbor);
                }
                else if(color[neighbor] == color[curr]) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int> color(nodes,-1);
        
        for(int i=0;i<nodes;i+=1){
            if(color[i] == -1){
                if(bfs(graph, color, i) == false) return false;
            }
        }
        return true;
    }
};
