class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> ans = image;

        int startColor = image[sr][sc];
        if (startColor == color) return image;

        q.push({sr, sc});
        ans[sr][sc] = color;

        int changeRow[] = {0, 1, 0, -1};
        int changeCol[] = {-1, 0, 1, 0};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newRow = row + changeRow[i];
                int newCol = col + changeCol[i];

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && ans[newRow][newCol] == startColor) {
                    q.push({newRow, newCol});
                    ans[newRow][newCol] = color;
                }
            }
        }
        return ans;
    }
};