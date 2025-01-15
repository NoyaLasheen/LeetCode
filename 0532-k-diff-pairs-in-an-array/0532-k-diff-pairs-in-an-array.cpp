class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int pairs = 0;
        for (int i : nums) {
            if (freq.find(i) == freq.end()) {
                if (freq.find(i + k) != freq.end()) pairs++;
                if (freq.find(i - k) != freq.end()) pairs++; 
            }
            freq[i]++;
            if (k == 0 && freq[i] == 2) pairs++;
        }
        return pairs;
    }
};

