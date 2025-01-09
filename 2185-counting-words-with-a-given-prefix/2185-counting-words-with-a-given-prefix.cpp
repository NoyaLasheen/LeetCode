class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            int j = 0;
            while (j < pref.length() && words[i][j] == pref[j]) {
                j++;
            }
            if (j == pref.length()) {
                count++;
            }
        }
        return count;
    }
};