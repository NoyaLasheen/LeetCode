class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int open = 1, close = 0;

        for (int i = 1; i < s.length(); i++)  {
            if (s[i] == '(') open++;
            else close++;
            if (open == close) {
                ans.append(s.substr(i - (open + close - 2), open + close - 2));
                open = 0, close = 0;
            }
        }
        return ans;
    }
};