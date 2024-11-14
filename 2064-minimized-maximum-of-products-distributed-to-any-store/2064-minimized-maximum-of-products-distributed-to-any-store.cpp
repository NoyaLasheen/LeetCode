class Solution {
public:
    bool canDistribute(int x, int n, vector<int> &quantities) {
        int stores = 0;
        for (int i = 0; i < quantities.size(); i++) {
            stores += ceil((double)quantities[i] / x);
        }
        return stores <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        
        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());
        int mid, ans = INT_MAX;
        
        while (low <= high) {
            mid = low + (high - low) / 2;
            
            if (canDistribute(mid, n, quantities)) {
                ans = min(ans, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
        
    }
};