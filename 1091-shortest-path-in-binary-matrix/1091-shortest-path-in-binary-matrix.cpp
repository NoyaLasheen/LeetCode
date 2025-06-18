class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        int changeRow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int changeCol[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        q.push({1, {0, 0}});
        dist[0][0] = 1;

        while (! q.empty()) {
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nRow = row + changeRow[i];
                int nCol = col + changeCol[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] == 0) {
                    if (dis + 1 < dist[nRow][nCol]) {
                        dist[nRow][nCol] = dis + 1;
                        q.push({dis + 1, {nRow, nCol}});
                    }
                }
            }
        }

        return dist[n -1][n - 1] == 1e9 ? -1 : dist[n -1][n - 1];

    }
};