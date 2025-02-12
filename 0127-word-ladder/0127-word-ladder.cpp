class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> words(wordList.begin(), wordList.end());
        words.erase(beginWord);

        while (!q.empty()) {
            string s = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (s == endWord) return steps;

            for (int i = 0; i < s.size(); i++) {
                char org = s[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    s[i] = ch;
                    if (words.find(s) != words.end()) {
                        q.push({s, steps + 1});
                        words.erase(s);
                    }
                }
                s[i] = org;
            }
        }
        return 0;
    }
};