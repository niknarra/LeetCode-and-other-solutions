// Approach 1 - Convert the Adj Matrix into a List and then BFS to find total number of components
// TC and SC: O(n*n)

class Solution {
public:
    void bfs(int start, vector<vector<int>>& adj, vector<int>& vis) {
        queue<int> q;
        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int node : adj[curr]) {
                if (!vis[node]) {
                    vis[node] = 1;
                    q.push(node);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(n, 0); 
        int count = 0;     

        // Count connected components
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                bfs(i, adj, vis);
            }
        }

        return count;
    }
};

// Approach 2 - Same logic of using BFS, but use the matrix itself
// TC and SC: O(n * n)

class Solution {
public:
void bfs(int start, vector<vector<int>>& isConnected, vector<int>& vis) {
        queue<int> q;
        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {
                if (isConnected[curr][neighbor] == 1 && !vis[neighbor]) {
                    vis[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> vis(n, 0); 
        int count = 0;     

        // Count connected components
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                bfs(i, isConnected, vis);
            }
        }

        return count;
    }
};
