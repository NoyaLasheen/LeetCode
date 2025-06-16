class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff = 0;
        int minEl = nums[0];
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] < minEl) {
                minEl = nums[i];
            } else {
                maxDiff = max(maxDiff, nums[i] - minEl);
            }
        }
        return maxDiff == 0 ? -1 : maxDiff;
    }
};