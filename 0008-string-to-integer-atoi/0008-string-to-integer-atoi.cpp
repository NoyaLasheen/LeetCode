class Solution {
    int helperAtoi(string s, int idx, int& sign, int& ans, bool started) {
        // Base cases
        // String is over or an alphabet encountered
        if (idx >= s.length() || started && !isdigit(s[idx])) 
            return ans * sign;

        // Encountering leading spaces
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
            int digit = s[idx] - '0';

            // Check for overflow conditions before updating ans
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;

            return helperAtoi(s, idx + 1, sign, ans, true);
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