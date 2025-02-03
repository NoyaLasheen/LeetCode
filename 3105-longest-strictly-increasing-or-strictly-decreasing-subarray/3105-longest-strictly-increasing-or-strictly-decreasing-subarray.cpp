class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1;
        int dec = 1;
        int maxInc = 1, maxDec = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                inc++;
                dec = 1;
                maxInc = max(maxInc, inc);
            } else if (nums[i] < nums[i - 1]) {
                dec++;
                inc = 1;
                maxDec = max(maxDec, dec);
            } else {
                dec = 1;
                inc = 1;
            }
        }
        return maxInc > maxDec ? maxInc : maxDec;
    }
};