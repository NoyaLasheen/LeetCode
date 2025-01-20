class Solution {
    vector<string> ans;
    void generate(string s, int n, int open, int close) {
        if (s.length() == 2 * n) {
            ans.push_back(s);
            return;
        }
        if (open < n) generate(s + '(', n, open + 1, close);
        if (close < open) generate(s + ')', n, open, close + 1);
    }
public:
    vector<string> generateParenthesis(int n) {
        string s;
        int close = 0; 
        int open = 0;
        generate(s, n, 0, 0);
        return ans;
    }
};