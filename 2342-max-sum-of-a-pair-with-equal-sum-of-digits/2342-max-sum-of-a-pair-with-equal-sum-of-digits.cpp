class Solution {
    int digSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        int maxSum = -1;
        unordered_map<int, int> maxNum;
        for (int i : nums) {
            int sum = digSum(i);
            if (maxNum.count(sum)) {
                maxSum = max(maxSum, maxNum[sum] + i);
                maxNum[sum] = max(maxNum[sum], i);
            } else {
                maxNum[sum] = i;
            }
        }
        return maxSum;
    }
};