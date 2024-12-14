class Solution {
    
    bool can_sum(vector<int>& nums, int div, int threshold) {
        long long sum = 0;  
        
        for (int x : nums) {
            sum += ceil((double)x / (double)div);
        }
        return sum <= threshold;
    }
    
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = INT_MIN;
        
        for (int x : nums) {
            high = max(high, x);
        }
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (can_sum(nums, mid, threshold)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};