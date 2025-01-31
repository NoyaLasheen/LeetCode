class Solution {
    int helperAtoi(string s, int idx, int& sign, int& ans, bool started) {
        // Base cases
        // String is over or an alphabet encountered
        if (idx >= s.length() || started && !isdigit(s[idx])) 
            return ans * sign;

        // Encountering leading zeroes
        if (!started && s[idx] == ' ') {  
            return helperAtoi(s, idx + 1, sign, ans, false);
        } 
        
        // Handle signs at the beginning
        if (!started && (s[idx] == '-' || s[idx] == '+')) {
            sign = (s[idx] == '-') ? -1 : 1;
            return helperAtoi(s, idx + 1, sign, ans, true);
        }        

        // Encountering digits
        if (isdigit(s[idx])) {
            ans = ans * 10 + s[idx] - '0';

            if (sign == 1 && ans >= INT_MAX) return INT_MAX;
            if (sign == -1 && ans * sign <= INT_MIN) return INT_MIN;

            helperAtoi(s, idx + 1, sign, ans, true);
        } 

        return ans * sign;
    }
public:
    int myAtoi(string s) {
        int sign = 1;
        int ans = 0;
        return helperAtoi(s, 0, sign, ans, false);
    }
};