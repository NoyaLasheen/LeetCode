class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.length() <= 1) return s;
        
        long long prefix = 0;
        long long suffix = 0;
        int base = 29;
        int mod = 1e9 + 7;
        long long power = 1;
        int ind = 0;
        
        for (int i = 0; i < s.length(); i++) {
            int ch = s[i] - 'a' + 1;
            prefix = (prefix * base) % mod;
            prefix = (prefix + ch) % mod;
            suffix = (suffix + ch * power) % mod;
            power = (power * base) % mod;
            
            if (suffix == prefix) 
                ind = i;
        }
        string r = s.substr(ind + 1);
        reverse(r.begin(), r.end());
        return  r + s;
    }
};