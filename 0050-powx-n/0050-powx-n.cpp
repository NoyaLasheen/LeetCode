class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;
        double ans = 1.0;

        if (exp < 0) exp *= -1;

        while (exp) {
            if (exp % 2 == 0) {
                x *= x;
                exp /= 2;
            } else {
                ans *= x;
                exp -= 1;
            }
        }

        return n < 0 ? (double)1/(double)ans : ans;       
    }
};