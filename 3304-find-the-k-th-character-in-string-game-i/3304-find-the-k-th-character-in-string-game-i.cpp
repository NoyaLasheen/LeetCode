class Solution {
    void build (string &word, int k) {
        int n = word.length();
        if (n >= k) return;

        for (int i = 0; i < n && i <= k; i++) {
            if (word[i] == 'z') word += 'a';
            else word += (word[i] + 1);
        }

        build(word, k);
    }
public:
    char kthCharacter(int k) {
        string word = "a";
        build(word, k);
        return word[k - 1];
    }
};