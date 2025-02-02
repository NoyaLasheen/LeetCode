class Solution {
public:
    int romanToInt(string s) {
        int val = 0;
        unordered_map<char, int> freq;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == 'I') {
                if (freq.find('X') == freq.end() && freq.find('V') == freq.end()) val++;
                else val--;
            } else if (s[i] == 'X') {
                if (freq.find('L') == freq.end() && freq.find('C') == freq.end()) val += 10;
                else val -= 10;
            } else if (s[i] == 'C') {
                if (freq.find('D') == freq.end() && freq.find('M') == freq.end()) val += 100;
                else val -= 100;
            } else if (s[i] == 'V') {
                val += 5;
            } else if (s[i] == 'L') {
                val += 50;
            } else if (s[i] == 'D') {
                val += 500;
            } else if (s[i] == 'M') {
                val += 1000;
            }
            freq[s[i]]++;
        }
        return val;
    }
};