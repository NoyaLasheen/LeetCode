class Solution {
    
    long long calc_hours(vector<int>& piles, int l) {
        long long hours = 0;
        for (int x : piles)  {
            hours += ceil((double)x / (double)l);
        }
        return hours;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        
        for (int x : piles)
            high = max(high, x);
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long hours = calc_hours(piles, mid);
            if (hours > h) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};