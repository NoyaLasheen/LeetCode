class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int left_sum[nums.size()];
        int right_sum[nums.size()];
        
        
        left_sum[0] = 0;
        for (int i = 1; i < nums.size(); i++) {
            left_sum[i] = left_sum[i - 1] + nums[i - 1];
        }
        
        right_sum[nums.size() - 1] = 0;
        
        for (int i = nums.size() - 2; i >= 0; i--) {
            right_sum[i] = right_sum[i + 1] + nums[i + 1];
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (left_sum[i] == right_sum[i]) {
                return i;
            }
        }
        
        return -1;
        
    }
};