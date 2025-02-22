class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 1. Build the adjacency list
        // As we have a pair [a,b] b is the pre-req of a, so b->a
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        // 2. Get the indegrees of all the nodes
        vector<int> degrees(numCourses, 0);
        for(int i=0;i<numCourses;i+=1){
            for(int neighbor:adj[i]){
                degrees[neighbor] += 1;
            }
        }

        // 3. Get the nodes with 0 indegrees and push to stack for BFS
        stack<int> st;
        for(int i=0;i<numCourses;i+=1){
            if(degrees[i] == 0) st.push(i);
        }

        // 4. Init a count variable and start BFS as long as the stack is not empty
        // Increment the count with every iteration
        int cnt = 0;
        while(!st.empty()){
            int curr = st.top();
            st.pop();

            for(int neighbor:adj[curr]){
                degrees[neighbor] -= 1;
                if(degrees[neighbor] == 0) st.push(neighbor);
            }
            cnt += 1;
        }

        // 5. If the count is equal to the number of courses, it means we were able to schedule all of them linearly
        // and as per the order so no cycle
        return cnt == numCourses;
    }
};
