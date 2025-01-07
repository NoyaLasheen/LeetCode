class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> ans;
        for (string word : words) {
            for (int i = 0; i < words.size(); i++) {
                if (word != words[i]) {
                    size_t idx = words[i].find(word);
                    if (idx != string::npos) {
                        ans.insert(word);
                    }
                }
            }
        }
        vector<string> v(ans.begin(), ans.end());
        return v;
    }
};