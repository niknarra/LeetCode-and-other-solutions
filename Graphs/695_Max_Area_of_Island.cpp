// Number of Islands Approach but with a count var

class Solution {
    int ans = 0;
    int count = 0;
public:
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) return;

        grid[i][j] = 0;
        count += 1; // Everytime there is a land, increase the size
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        for(int i=0;i<rows;i+=1){
            for(int j=0;j<cols;j+=1){
                if(grid[i][j] == 1){
                    dfs(grid, i, j);
                    ans = max(ans, count);
                    count = 0; // Reset the island size counter variable for each island
                }
            }
        }
        return ans;
    }
};
