class Solution {
public:
    bool isAnagram(string s, string t) {
        
        map<char, int> map_s, map_t;
        
        for (char ch : s) map_s[ch]++;
        for (char ch : t) map_t[ch]++;
        
        return map_s == map_t;
    }
};