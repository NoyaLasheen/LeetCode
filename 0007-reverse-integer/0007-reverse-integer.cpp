class Solution {
public:
    int reverse(int x) {
        
        if (x >= INT_MAX || x <= INT_MIN) return 0;
        int rev = 0;
        int i;
        if (x < 0) {
            i = -1 * x;
        } else {
            i = x;
        }
        for (; i > 0; i /= 10) {
            if (rev > INT_MAX / 10) return 0;
            rev = rev * 10 + i % 10;
        }
        if (x < 0) {
            return -1 * rev;
        } else return rev;
    }
};