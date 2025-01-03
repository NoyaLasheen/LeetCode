class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> alpha1;
        unordered_map<char, char> alpha2;

        for (int i = 0; i < s.length(); i++) {
            if (alpha1.find(s[i]) != alpha1.end() && alpha1[s[i]] != t[i]) return false;
            if (alpha2.find(t[i]) != alpha2.end() && alpha2[t[i]] != s[i]) return false;
            alpha1[s[i]] = t[i];
            alpha2[t[i]] = s[i];
        }
        return true;
    }
};