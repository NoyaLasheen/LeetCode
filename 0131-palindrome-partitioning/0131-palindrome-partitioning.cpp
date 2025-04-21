class Solution {
    bool isPalindrome(string s) {
        int n = s.length();
        for (int i = 0; i < n/2; i++) {
            if (s[i] != s[n - i- 1]) return false;
        }
        return true;
    }
    void generate(string& s, vector<vector<string>>& ans, vector<string>& curr, int idx) {
        if (idx == s.length()) ans.push_back(curr);

        for (int i = idx; i < s.length(); i++) {
            string sub = s.substr(idx, i - idx + 1);
            if (isPalindrome(sub)) {
                curr.push_back(sub);
                generate(s, ans, curr, i + 1);
                curr.pop_back();
            }
        }
    } 
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        generate(s, ans, curr, 0);
        return ans;
    }
};