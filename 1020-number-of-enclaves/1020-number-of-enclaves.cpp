class Solution {
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int row, int col, int changeRow[], int changeCol[]) {
        visited[row][col] = 1;

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < 4; i++) {
            int newRow = row + changeRow[i];
            int newCol = col + changeCol[i];

            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && visited[newRow][newCol] == 0 && grid[newRow][newCol] == 1) dfs(grid, visited, newRow, newCol, changeRow, changeCol);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int changeRow[] = {-1, 0, 1, 0};
        int changeCol[] = {0, -1, 0, 1};
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) {
                visited[0][j] = 1;
                dfs(grid, visited, 0, j, changeRow, changeCol);
            }
            if (grid[m - 1][j] == 1) {
                visited[m - 1][j] = 1;
                dfs(grid, visited, m - 1, j, changeRow, changeCol);
            }
        }

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                visited[i][0] = 1;
                dfs(grid, visited, i, 0, changeRow, changeCol);
            }
            if (grid[i][n - 1] == 1) {
                visited[i][n - 1] = 1;
                dfs(grid, visited, i, n - 1, changeRow, changeCol);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) count++;
            }
        }
        return count;
    }
};