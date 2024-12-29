class Solution {
    #define ll long long
    
    int mem[1001][1001];
    int target_size;
    int word_size;
    int MOD = 1000000007;
    int n;

    vector<vector<int>> char_freq;

    int countWays(vector<string>& words, string& target, int idx, int pos) {
        if (pos == target_size)
            return idx <= word_size;

        if (idx >= word_size || (word_size - idx < target_size - pos))
            return 0;
        
        if (mem[idx][pos] != -1)
            return mem[idx][pos];
        
        char curr = target[pos];

        ll count_by_matching = countWays(words, target, idx + 1, pos + 1) % MOD;
        ll count_without_matching = countWays(words, target, idx + 1, pos);
        ll total_ways = (count_without_matching + (ll)char_freq[idx][curr - 'a'] * count_by_matching) % MOD;

        return mem[idx][pos] = total_ways;
    }
public:
    int numWays(vector<string>& words, string target) {
        target_size = target.size();
        word_size = words[0].size();
        n = words.size();
        char_freq = vector<vector<int>>(word_size,vector<int>(26,0));


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < word_size; j++) {
                char curr = words[i][j];
                char_freq[j][curr - 'a']++;
            }
        }

        memset(mem, -1, sizeof(mem));
        return countWays(words, target, 0, 0);
    }
};