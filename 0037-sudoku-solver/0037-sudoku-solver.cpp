class Solution {
    bool isValid(int r, int c, char d, vector<unordered_set<char>>& rows, vector<unordered_set<char>>& cols, vector<unordered_set<char>>& grids) {
        int boxIndex = (r / 3) * 3 + (c / 3);
        return rows[r].count(d) == 0 && cols[c].count(d) == 0 && grids[boxIndex].count(d) == 0;
    }

    bool solve(vector<vector<char>>& board, vector<pair<int, int>>& empty, int idx, vector<unordered_set<char>>& rows, vector<unordered_set<char>>& cols, vector<unordered_set<char>>& grids) {
        if (idx == empty.size()) return true;

        int r = empty[idx].first;
        int c = empty[idx].second;
        int boxIndex = (r / 3) * 3 + (c / 3);


        string num = "123456789";
        for (int i = 0; i < 9; i++) {
            char d = num[i];
            if (isValid(r, c, d, rows, cols, grids)) {
                rows[r].insert(d);
                cols[c].insert(d);
                grids[boxIndex].insert(d);
                board[r][c] = d;
                
                if (solve(board, empty, idx + 1, rows, cols, grids)) return true;

                rows[r].erase(d);
                cols[c].erase(d);
                grids[boxIndex].erase(d);
                board[r][c] = '.';
            }
        }
        return false;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int, int>> empty;
        vector<unordered_set<char>> rows(9), cols(9), grids(9);
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = board[i][j];
                if (ch == '.') {
                    empty.push_back({i, j});
                } else {
                    rows[i].insert(ch);
                    cols[j].insert(ch);
                    int boxIndex = (i / 3) * 3 + (j / 3);
                    grids[boxIndex].insert(ch);
                }
            }
        }

        solve(board, empty, 0, rows, cols, grids);
    }
};