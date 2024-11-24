class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long neg_count = 0;
        long long sum = 0;
        long long min_val = INT_MAX;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                if (matrix[i][j] < 0) {
                    neg_count++;
                } 
                min_val = min(min_val, abs(static_cast<long long>(matrix[i][j])));
                sum += abs(matrix[i][j]);
            }
        }
        
        if (neg_count % 2 == 0) {
            return sum;
        } else {
            return sum - 2 * min_val;
        }
    }
};