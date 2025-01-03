class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int count = 0;
        long long sum = 0;
        long long prefix_sum = 0;
        for (int x : nums) {
            sum += x;
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            prefix_sum += nums[i];
            if (prefix_sum >= sum - prefix_sum) {
                count++;
            }
        }
        return count;
    }
};