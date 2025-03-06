class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // 0. Prereqs
        int row = mat.size();
        int col = mat[0].size();

        // Initialize the answer vector of vectors and queue of pairs
        vector<vector<int>> dist(row, vector<int>(col, -1));
        queue<pair<int, int>> q;

        // 1. Traverse the matrix and get all the 0 positions
        // And also mark 0 cells as 0 distanced in distance array
        for(int i=0;i<row;i+=1){
            for(int j=0;j<col;j+=1){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        // 2. Start BFS from the queue and form delta rows and cols for 4 way traversal
        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {1, 0, -1, 0};

        while(!q.empty()){
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();

            for(int i=0;i<4;i+=1){
                int newRow = currRow+delRow[i];
                int newCol = currCol+delCol[i];
                // Validate new row and col are within bounds
                // and also not visited (-1)
                if(
                    newRow >= 0 && newRow < row &&
                    newCol >= 0 && newCol < col &&
                    dist[newRow][newCol] == -1
                ){
                    // If yes, then their distance will be current distance + 1
                    dist[newRow][newCol] = dist[currRow][currCol] + 1;
                    q.push({newRow, newCol});
                }
            }
        }
        return dist;
    }
};
