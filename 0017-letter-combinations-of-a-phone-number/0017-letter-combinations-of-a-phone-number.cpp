class Solution {
    void generate(vector<string>& ans, string& curr, string digits, int idx, unordered_map<char, string> mp) {
        if (curr.length() == digits.length()) ans.push_back(curr);

        char ch = digits[idx];
        for (int i = 0; i < mp[ch].length(); i++) {
            curr += mp[ch][i];
            generate (ans, curr, digits, idx + 1, mp);
            curr.pop_back();
        }
        if (curr.length() > digits.length()) return;

    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return {};
        
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> ans;
        string curr;

        generate(ans, curr, digits, 0, mp);
        return ans;
    }
};