class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels;
        vector <int>result;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');

        vector<int> prefix;
        int n = words[0].length();
        if (vowels.find(words[0][0]) != vowels.end() && vowels.find(words[0][n - 1]) != vowels.end()) {
            prefix.push_back(1);
        } else {
            prefix.push_back(0);
        }
        int curr = prefix[0];
        for (int i = 1; i < words.size(); i++) {
            int n = words[i].length();
            if (vowels.find(words[i][0]) != vowels.end() && vowels.find(words[i][n - 1]) != vowels.end()) {
                prefix.push_back(++curr);
            } else {
                prefix.push_back(curr);
            }
        }

        for (auto& query : queries) {
            if (query[0] != 0) {
                result.push_back(prefix[query[1]] - prefix[query[0] - 1]);
            } else {
                result.push_back(prefix[query[1]]);
            }
        }
        return result;
    }
};