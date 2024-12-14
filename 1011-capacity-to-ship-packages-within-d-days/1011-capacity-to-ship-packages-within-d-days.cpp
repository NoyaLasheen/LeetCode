class Solution {
    
    bool can_ship(vector<int>&weights, int days, int limit) {
        int count = 1;
        int sum = 0;
        
        for (int x : weights) {
            if (sum + x <= limit) {
                sum += x;
            } else {
                count++;
                sum = x;
            }
        }
        return count <= days;
    }
    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (can_ship(weights, days, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};