class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int l = 0, r = 0, maxFreq = 0;
        long long sum = 0;
        while (r < nums.size()) {
            sum += nums[r];
            int freq = r - l + 1;
            if (static_cast<long long>(nums[r]) * freq <= sum + k) {
                maxFreq = max(maxFreq, freq);
            } else {
                sum -= nums[l++];
            }
            r++;
        }
        return maxFreq;
    }
};