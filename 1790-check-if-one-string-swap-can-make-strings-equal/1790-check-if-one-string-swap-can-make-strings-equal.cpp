class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;
        int mismatchCount = 0;
        vector<char> mismatches;

        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                mismatchCount++;
                mismatches.push_back(s1[i]);
                mismatches.push_back(s2[i]);
            }
            if (mismatchCount > 2) return false;
        }
        if (mismatches.size() == 4 && mismatches[0] == mismatches[3] && mismatches[1] == mismatches[2]) return true;
            return false;
    }            
};