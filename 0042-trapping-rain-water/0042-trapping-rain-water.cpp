class Solution {
public:
    int trap(vector<int>& height) {
        int r = height.size() - 1;
        int l = 0;
        int max_left = 0;
        int max_right = 0;
        int rain = 0;
        
        while (l <= r) {
            if (height[l] <= height[r]) {
                if (height[l] < max_left) {
                    rain += (max_left - height[l]);
                    
                } else {
                    max_left = height[l];
                }
                l++;
            } else {
                if (height[r] < max_right) {
                    rain += (max_right - height[r]);
                } else {
                    max_right = height[r];
                }
                r--;
            }
        }
        
        return rain;
    }
};