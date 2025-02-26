class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minSum = 0, maxSum = 0,minn = 0, maxx = 0;
        for (int i : nums) {
            if (minSum + i > 0) minSum = 0;
            else minSum += i;
            if (maxSum + i < 0) maxSum = 0;
            else maxSum += i;
            maxx = max(maxx, maxSum);
            minn = min(minn, minSum);
        }
        return max(maxx, abs(minn));
    }
};