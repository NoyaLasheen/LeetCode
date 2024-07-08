class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int count = 0;
        int max_ones = INT_MIN;
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                count++;
            }
            while (count > 1) {
                if (nums[left] == 0) {
                    count--;
                }
                left++;
            }
            max_ones = max(max_ones, right - left);
            
        }
        return max_ones;
    }
};