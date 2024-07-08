class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_len = INT_MIN;
        
        int left = 0;
        int count = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                count++;
            }
            while (count > k) {
                if (nums[left] == 0) {
                    count--;
                
                }
                left++;
            }
            max_len = max(max_len, right - left + 1); 
        }
        return max_len;
        
    }
};