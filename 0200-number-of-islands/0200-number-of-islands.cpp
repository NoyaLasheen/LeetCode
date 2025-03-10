class Solution {
    void dfs(int row, int col, vector<vector<char>>& grid, vector<int>& changeRow,vector<int>& changeCol) {
        grid[row][col] = '0';
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < 4; i++) {
            int newRow = row + changeRow[i];
            int newCol = col + changeCol[i];

            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == '1') {
                dfs(newRow, newCol, grid, changeRow, changeCol);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<int> changeRow = {0, -1, 0, 1};
        vector<int> changeCol = {-1, 0, 1, 0};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid, changeRow, changeCol);
                }
            }
        }
        return count;        
    }
};