class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string curr = strs[0];
        for (string str : strs) {
            for (int i = 0; i < str.length() && i < curr.length(); i++) {
                if (curr[i] != str[i]) {
                    curr = curr.substr(0, i);
                    break;
                }
            }
        }
        return curr;
    }
};