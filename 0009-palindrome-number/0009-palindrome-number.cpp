class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x >= INT_MAX) {
            return false;
        } 
        
        long int rev = 0;
        
        for (int i = x; i > 0; i /= 10) {
            if (rev * 10 >= INT_MAX) return false;
            rev = rev * 10 + i % 10;
        }
        
        return rev == x;
    }
};