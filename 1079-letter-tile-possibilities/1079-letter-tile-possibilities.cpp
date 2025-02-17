class Solution {
    void generate(string tiles, string& s, int& count, unordered_map<char, int> freq) {
        int count_0 = 0;
        for (auto& [ch, val] : freq) {
            if (val == 0) count_0++;
        } 
        if (count_0 == freq.size()) return;

        for (auto& [ch, val] : freq) {
            if (val > 0) {
                val--;
                count++;
                s.push_back(ch);
                generate(tiles, s, count, freq);
                s.pop_back();
                val++;
            } 
        }
    }
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for (char ch : tiles) freq[ch]++;
        string s = "";
        int count = 0;

        generate(tiles, s, count, freq);
        return count;
    }
};