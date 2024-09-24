class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> num_set;
        
        int len = 0;
        int max_len = INT_MIN;
        
        for (int i : arr1) {
            while (i > 0) {
                num_set.insert(i);
                i /= 10;
            }
        }
        
        for (int i : arr2) {
            while (i > 0) {
                if (num_set.find(i) != num_set.end()) {
                    len = floor(log10(i) + 1);
                }
                max_len = max(max_len, len);
                i /= 10;
            }
        }
        
        return max_len;
        
        
    }
};