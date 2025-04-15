class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        
        queue<pair<vector<int>, int>> q;
        q.push({entrance, 0});

        int changeRow[] = {0, -1, 0, 1};
        int changeCol[] = {-1, 0, 1, 0};

        while (!q.empty()) {
            int x = q.front().first[0];
            int y = q.front().first[1];
            int dis = q.front().second;
            q.pop();

            if (x != entrance[0] || y != entrance[1]) {
                if (x == 0 || x == m - 1 || y == 0 || y == n - 1) return dis;
            }

            for (int i = 0; i < 4; i++) {
                int row = x + changeRow[i];
                int col = y + changeCol[i];

                if (row >= 0 && row < m && col >= 0 && col < n && maze[row][col] == '.') {
                    q.push({{row, col}, dis + 1});
                }
            }
        }

        return -1;
    }
};