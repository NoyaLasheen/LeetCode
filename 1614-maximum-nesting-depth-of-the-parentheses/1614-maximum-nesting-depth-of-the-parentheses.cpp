class Solution {
public:
    int maxDepth(string s) {
        int ans = INT_MIN;
        int open = 0;
        int close = 0;
        for (char ch : s) {
            if (ch == '(') {
                open++;
            } else if (ch == ')') {
                close++;
            }
            ans = max(ans, open - close);
        }
        return ans;
    }
};