class Solution {
    bool find(vector<vector<char>>& board, string word, int idx, int row, int col, int m, int n, int len) {
        if (idx == len - 1) return true;

        board[row][col] = '*';

        int changeRow[] = {-1, 0, 1, 0};
        int changeCol[] = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++) {
            int newRow = row + changeRow[i];
            int newCol = col + changeCol[i];

            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && board[newRow][newCol] != '*' && board[newRow][newCol] == word[idx + 1]) {
                
                if (find(board, word, idx + 1, newRow, newCol, m, n, len)) {
                    return true;
                }
                
            }
        }
        board[row][col] = word[idx];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int len = word.length();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] ==  word[0]) {
                    if (find(board, word, 0, i , j, m, n, len)) return true;
                }
            }
        }
        return false;
    }
};