class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int count = 0;
        for (int i : nums) {
            if (freq.find(i - k) != freq.end()) count += freq[i - k];
            if (freq.find(i + k) != freq.end()) count += freq[i + k];
            freq[i]++;
        }
        return count;
    }
};