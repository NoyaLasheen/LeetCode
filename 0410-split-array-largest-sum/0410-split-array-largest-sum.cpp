class Solution {
    
    bool can_split(vector<int>& nums, int k, int mid) {
        int count = 1;
        int sum = 0;
        for (int x : nums) {
            if (sum + x <= mid) {
                sum += x;
            } else {
                count++;
                sum = x;
            }
        }
        return count <= k;
    }
    
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (can_split(nums, k, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};