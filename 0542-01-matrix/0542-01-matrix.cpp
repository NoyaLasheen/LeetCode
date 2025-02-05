class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        int changeRow[] = {0, 1, 0, -1};
        int changeCol[] = {-1, 0, 1, 0};

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            ans[row][col] = dist;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newRow = row + changeRow[i];
                int newCol = col + changeCol[i];

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && visited[newRow][newCol] == 0) {
                    visited[newRow][newCol] = 1;
                    q.push({{newRow, newCol}, dist + 1});
                }
            }
        }
        return ans;
    }
};