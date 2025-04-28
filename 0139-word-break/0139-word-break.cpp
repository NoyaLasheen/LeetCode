class Solution {
    bool find(string s, set<string>& wordSet, int idx, vector<int>& state, int n) {
        if (idx == n) return true;
        if (state[idx] != -1) return state[idx];

        string temp = "";
        for (int i = idx; i < n; i++) {
            temp += s[i];
            if (wordSet.find(temp) != wordSet.end()) {
                if (find(s, wordSet, i + 1, state, n)) {
                    return true;
                }
            }
        }
        return state[idx] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> state(n, -1);
        // string temp = "";
        return find(s,wordSet, 0, state, n);
    }
};