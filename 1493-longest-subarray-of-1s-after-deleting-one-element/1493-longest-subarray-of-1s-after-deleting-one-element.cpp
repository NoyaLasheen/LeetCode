class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int n = nums.size();
        int count = 0;
        int l = 0, r = 0;
        int size = 0;

        for (; r < n; r++) {
            if (nums[r] == 0) count++;
            while (count > 1) {
                if (nums[l] == 0) count--;
                l++;
            }
            size = max(size, r - l);
        }

        return size;
    }
};