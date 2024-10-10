class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
                
        int n = nums.size();
        vector<int> NGE(n, 0);
        
        NGE[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            NGE[i] = max(nums[i], NGE[i + 1]);
        }
        
        int l = 0;
        int maxWidth = INT_MIN;
        
        for (int r = 0; r < n; r++) {
            while (nums[l] > NGE[r]) 
                l++;
            maxWidth = max(maxWidth, r - l);
        }
        
        return maxWidth;
    }
};