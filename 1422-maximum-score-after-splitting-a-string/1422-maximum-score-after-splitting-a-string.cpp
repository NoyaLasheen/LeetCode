class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int one = 0;
        for (char ch : s) {
            if (ch == '1') one++;
        }
        int count = 0;
        int score = INT_MIN;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') count++;
            score = max(score, count + one - (i + 1 - count));
        }
        return score;
    }
};