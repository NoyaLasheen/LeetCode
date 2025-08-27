class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiag = 0;
        int maxArea = 0;
        int n = dimensions.size();

        for (int i = 0; i < n; i++) {
            int a = dimensions[i][0];
            int b = dimensions[i][1];
            int diag = a * a + b * b;
            int area = a * b;

            if (diag > maxDiag || (diag == maxDiag && area > maxArea)) {
                maxArea = area;
                maxDiag = diag;
            }
            
        }
        return maxArea;
    }
};