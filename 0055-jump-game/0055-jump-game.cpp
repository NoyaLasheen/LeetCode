class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        int maxIdx = 0;
        
        for (int i = 0; i < n; i++) {
            maxIdx = max(maxIdx, i + nums[i]);
            if (maxIdx <= i) return false;
            if (maxIdx >= n - 1) return true;
        }
        return true;
    }
};