class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int max_len = 0;
        unordered_map<char, int> mp;
        for (int r = 0; r < s.length(); r++) {
            if (mp.count(s[r])) {
                l = mp[s[r]] + 1;
            } 
            mp[s[r]] = r;
            max_len = max(max_len, r - l + 1);
        }
        return max_len;
    }
};