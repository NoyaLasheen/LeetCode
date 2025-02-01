class Solution {
    vector<int> findLPS(string& pattern) {
        int n = pattern.size();
        vector<int> LPS(n);

        int i = 1;
        int j = 0;
        LPS[0] = 0;

        while (i < n) {
            if (pattern[i] == pattern[j]) {
                LPS[i] = ++j;
                i++;
            } else if (j > 0) {
                j = LPS[j - 1];
            } else {
                LPS[i] = 0;
                i++;
            }
        }
        return LPS;
    }

    bool KMP(string s, string goal, vector<int>& LPS) {
        int m = s.length();
        int n = goal.length();

        int i = 0, j = 0;

        while (i < m) {
            if (j == n) return true;

            if (s[i] == goal[j]) i++, j++;
            else if (j > 0) j = LPS[j - 1];
            else i++;
        }
        return false;
    }
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;

        string text = s + s;
        vector<int> LPS = findLPS(goal);
        return KMP(text, goal, LPS);
    }
};