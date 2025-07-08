class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> diff(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        diff[0][0] = 0;
        pq.push({0, {0, 0}});

        int cR[] = {-1, 0, 1, 0};
        int cC[] = {0, 1, 0, -1};

        while (! pq.empty()) {
            int effort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (row == m - 1 && col == n - 1) {
                return effort;  
            }

            for (int i = 0; i < 4; i++) {
                int newR = row + cR[i];
                int newC = col + cC[i];

                if (newR >= 0 && newR < m && newC >= 0 && newC < n) {
                    int newEff = max(effort, abs(heights[row][col] - heights[newR][newC]));
                    if (newEff < diff[newR][newC]) {
                        diff[newR][newC] = newEff;
                        pq.push({newEff, {newR, newC}});
                    }
                }
            }
        }
        
        
        return diff[m - 1][n - 1];
    }
};