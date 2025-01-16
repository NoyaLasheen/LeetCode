class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int map1[26] = {0};
        int map2[26] = {0};
        for (char ch : s1) map1[ch - 'a']++;
        int start = 0;
        for (int last = 0; last < s2.length(); last++) {
            map2[s2[last] - 'a']++;
            if (last - start + 1 > s1.length()) {
                map2[s2[start] - 'a']--;
                start++;
            }
            if (equal(begin(map1), end(map1), begin(map2))) return true;
        }
        return false;
    }
};
