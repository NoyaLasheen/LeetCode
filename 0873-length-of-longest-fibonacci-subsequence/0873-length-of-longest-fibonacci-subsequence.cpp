class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++) {
            hash[arr[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(n, 2));
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int ele = arr[j] - arr[i];
                if (hash.find(ele) != hash.end() && hash[ele] < i) {
                    dp[i][j] = dp[hash[ele]][i] + 1;
                    max_len = max(max_len,dp[i][j]);
                }
            }
        }
        return max_len;
    }
};