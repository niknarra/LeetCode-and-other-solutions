// Similar to finding the number of components, but we need to find the 4-directional neighbors
// BFS approach

class Solution {
public:
// Helper function for BFS Traversal
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        vis[row][col] = 1; // Mark the passed row and col as visited

        int row_size = grid.size();
        int col_size = grid[0].size();

        queue<pair<int, int>> q; // Create a queue that can hold both row and col
        q.push({row, col}); // Push the starting row and col

	// Generate the delta row and cols,
	// Basically, the row and col will change by -1 or 1 if we go left or right or top or bottom
        int delrow[] = {-1, 0, 1, 0}; 
        int delcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
	// Get the current row and col
            int curr_row = q.front().first;
            int curr_col = q.front().second;
            q.pop();
	// Get the neighbors using deltas
            for (int i = 0; i < 4; i++) { 
                int neighborRow = curr_row + delrow[i];
                int neighborCol = curr_col + delcol[i];
	// Validate with 4 conditions,
	// 1. Check if the row is within bounds
	// 2. Check if the column is within bounds
	// 3. Check if the current row and col points to a land(1 in this case)
	// 4. Check if it is not already visited

                if (neighborRow >= 0 && neighborRow < row_size &&
                    neighborCol >= 0 && neighborCol < col_size &&
                    grid[neighborRow][neighborCol] == '1' &&
                    !vis[neighborRow][neighborCol]) {
	// Once validated, mark it as seen and push the row and col to the Q                    
                    vis[neighborRow][neighborCol] = 1;
                    q.push({neighborRow, neighborCol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        int row_size = grid.size();
        int col_size = grid[0].size();

        vector<vector<int>> vis(row_size, vector<int>(col_size, 0)); // Visited Array

        for (int row = 0; row < row_size; row++) {
            for (int col = 0; col < col_size; col++) {
	// If the row and col are not seen and it is a land,
                if (!vis[row][col] && grid[row][col] == '1') {
                    count++;
                    bfs(row, col, grid, vis);
                }
            }
        }

        return count;
    }
};

