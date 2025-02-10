class Solution {
    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int row, int col, int changeRow[], int changeCol[]) {
        int m = board.size();
        int n = board[0].size();

        visited[row][col] = 1;
        
        for (int i = 0; i < 4; i++) {
            int newRow = row + changeRow[i];
            int newCol = col + changeCol[i];

            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && visited[newRow][newCol] == 0 && board[newRow][newCol] == 'O') dfs(board, visited, newRow, newCol, changeRow, changeCol);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int changeRow[] = {-1, 0, 1, 0};
        int changeCol[] = {0, 1, 0, -1};

        for (int j = 0; j < n; j++) {
            if (visited[0][j] == 0 && board[0][j] == 'O') {
                dfs(board, visited, 0, j, changeRow, changeCol);
            }
            if (visited[m - 1][j] == 0 && board[m - 1][j] == 'O') {
                dfs(board, visited, m - 1, j, changeRow, changeCol);
            }                                        
        }

        for (int i = 0; i < m; i++) {
            if (visited[i][0] == 0 && board[i][0] == 'O') {
                dfs(board, visited, i, 0, changeRow, changeCol);
            }
            if (visited[i][n - 1] == 0 && board[i][n - 1] == 'O') {
                dfs(board, visited, i, n - 1, changeRow, changeCol);
            }                                        
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0 && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};