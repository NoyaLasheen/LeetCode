class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int l = 0, r = 0;
        map <char, int> mp;
        int maxLen = 0;
        while (r < s.length()) {
            mp[s[r]]++;
            while (mp[s[r]] > 1) {
                mp[s[l]]--;
                l++;
            } 
                r++;
            
            maxLen = max(maxLen, r - l);
        }
        return maxLen;
    }
};