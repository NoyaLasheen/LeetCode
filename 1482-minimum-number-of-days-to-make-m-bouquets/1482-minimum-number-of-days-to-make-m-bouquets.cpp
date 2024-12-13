class Solution {
    
    bool can_make(vector<int>& bloom, int m, int k, int day) {
        int count = 0;
        int bouq = 0;
        
        for (int i = 0; i < bloom.size(); i++) { 
            if (bloom[i] <= day) {
                count++;
            } else {
                bouq += (count / k);
                count = 0;
            }
        }
        bouq += (count / k);
        return bouq >= m;
    } 
    
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (1LL * m * 1LL * k > bloomDay.size()) return -1;
        
        int low = INT_MAX;
        int high = INT_MIN;
        
        for (int x : bloomDay) {
            low = min(low, x);
            high = max(high, x);
        }
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (! can_make(bloomDay, m, k, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};