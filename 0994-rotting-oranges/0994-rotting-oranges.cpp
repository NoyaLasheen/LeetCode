class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int, int>, int>> rotten;
        int freshCount = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int maxTime = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    rotten.push({{i,j},0});
                    visited[i][j] = 2;
                } else if (grid[i][j] == 1) freshCount++;            
            }
        }
        int changeRow[] = {0, 1, 0, -1};
        int changeCol[] = {-1, 0, 1, 0};
        while (!rotten.empty()) {
            int row = rotten.front().first.first;
            int col = rotten.front().first.second;
            int time = rotten.front().second;
            rotten.pop();
            maxTime = max(maxTime, time);
            for (int i = 0; i < 4; i++) {
                int newRow = row + changeRow[i];
                int newCol = col + changeCol[i];
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && visited[newRow][newCol] != 2 && grid[newRow][newCol] == 1) {
                    rotten.push({{newRow, newCol}, time + 1});
                    freshCount--;
                    visited[newRow][newCol] = 2;
                }
            }
        }
        return freshCount ? -1 : maxTime;
    }
};