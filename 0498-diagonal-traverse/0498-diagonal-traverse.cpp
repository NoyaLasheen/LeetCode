class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> res;
        int r = 0, c = 0;

        while (res.size() < m * n) {
            res.push_back(mat[r][c]);

            if ((r + c) % 2 == 0) {
                if (c == n - 1) r++;
                else if (r == 0) c++;
                else r--, c++;
            } else {
                if (r == m - 1) c++;
                else if(c == 0) r++;
                else r++, c--;
            }
        }

        return res;
    }
};