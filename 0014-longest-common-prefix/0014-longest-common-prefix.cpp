class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string curr = strs[0];
        for (string str : strs) {
            int i = 0;
            while (i < str.length() && i < curr.length() && curr[i] == str[i]) {
                i++;
            }
            curr = curr.substr(0, i);
            if (curr == "") break;
            
        }
        return curr;
    }
};