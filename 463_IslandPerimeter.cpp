class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    perimeter += dfs(grid, r, c);
                }
            }
        }

        return perimeter;
    }

private:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        // Base cases for DFS recursion
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) {
            return 1; // Water contributes 1 to perimeter
        }
        if (grid[r][c] == -1) {
            return 0; // Already visited land cell
        }

        // Mark cell as visited
        grid[r][c] = -1;

        // Explore neighbors (up, down, left, right)
        return (dfs(grid, r + 1, c) +
                dfs(grid, r - 1, c) +
                dfs(grid, r, c + 1) +
                dfs(grid, r, c - 1));
    }
};