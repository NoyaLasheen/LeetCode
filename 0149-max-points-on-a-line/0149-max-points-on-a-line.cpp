class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int maxP = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<double, int> mp;
            int x1 = points[i][0], y1 = points[i][1];
            int locmax = 0;

            for (int j = i + 1; j < n; j++) {
                
                int x2 = points[j][0], y2 = points[j][1];

                double slope = x2 - x1 == 0 ? INT_MAX : (double) ((y2 - y1)/ (x2 - x1));
                mp[slope]++;
                locmax = max(locmax, mp[slope]);

            }
            maxP = max(maxP, locmax + 1);
        }
        return maxP;
    }
};