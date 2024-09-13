class Solution {
public:
    string RLE(string s) {
        
        string ans = "";
        char ch = s[0];
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ch) 
                count++;
            else {
                ans = ans + to_string(count) + ch;
                ch = s[i];
                count = 1;
            }
            if (i == s.length() - 1) return ans + to_string(count) + ch;
        }
        return ans;
        
    }
    string countAndSay(int n) {
        if (n == 1) 
            return "1";
        else 
            return RLE(countAndSay(n - 1));
    }
};