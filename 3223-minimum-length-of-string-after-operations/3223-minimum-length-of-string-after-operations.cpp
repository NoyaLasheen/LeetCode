class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> hash;
        int len = 0;
        for (char ch : s) {
            hash[ch]++;
        }

        for (auto pair : hash) {
            while (pair.second > 2) {
                pair.second -= 2;
            }
            len += pair.second;
        }
        return len;
    }
};
