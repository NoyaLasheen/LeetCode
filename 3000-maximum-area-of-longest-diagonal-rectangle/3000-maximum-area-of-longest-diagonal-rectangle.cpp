class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        float maxRoot = 0;
        int idx = 0;
        int n = dimensions.size();

        for (int i = 0; i < n; i++) {
            int a = dimensions[i][0];
            int b = dimensions[i][1];

            if (sqrt(a * a + b * b) > maxRoot) {
                maxRoot = sqrt(a * a + b * b);
                idx =  i;
            }
        }
        return dimensions[idx][0] * dimensions[idx][1];
    }
};