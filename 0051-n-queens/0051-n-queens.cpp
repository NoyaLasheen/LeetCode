class Solution {
    bool isSafe(vector<string>& board, int row, int col, vector<int>& visCol, int n) {
        if (visCol[col] == 1) return false;

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }

    void place(vector<vector<string>>& ans, vector<string>& board, int n, vector<int>& visCol, int row) {
        if (row == n) ans.push_back(board);

        for (int i = 0; i < n; i++) {
            if (isSafe(board, row, i, visCol, n)) {
                board[row][i] = 'Q';
                visCol[i] = 1;
                place(ans, board, n, visCol, row + 1);
                board[row][i] = '.';
                visCol[i] = 0;
            }
        }      
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        vector<int> visCol(n, 0);
        place(ans, board, n, visCol, 0);
        return ans;
    }
};