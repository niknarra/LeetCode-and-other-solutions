// Kahn's Algorithm
// O(V+E)

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 1. Build the adjacency list
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        // 2. Calculate the indegrees for each node
        vector<int> degrees(numCourses, 0);
        for(int i=0;i<numCourses;i+=1){
            for(int neighbor:adj[i]){
                degrees[neighbor] += 1;
            }
        }

        // 3. Get the nodes with 0 degrees amd push to queue for BFS
        queue<int> q;
        for(int i=0;i<numCourses;i+=1){
            if(degrees[i] == 0) q.push(i);
        }

        // 4. While Q is not empty, perform BFS and push to ans vector
        vector<int> schedule;
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int neighbor:adj[curr]){
                degrees[neighbor]-=1;
                if(degrees[neighbor] == 0) q.push(neighbor);
            }

            schedule.push_back(curr);
        }

        // 5. Check if there was a topo sort made with all the courses or not
        return schedule.size() == numCourses ? schedule : vector<int>();
    }
};
