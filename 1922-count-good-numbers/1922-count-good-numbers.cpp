class Solution {
    long long modExp (long long base, long long exp, int mod) {
        long long result = 1;
        while (exp) {
            if (exp % 2) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
public:
    int countGoodNumbers(long long n) {
       
        long long odd = n / 2; 
        long long even = n % 2 ? n / 2 + 1 : n / 2;
        long long mod = 1000000007;

        return (modExp(5, even, mod) * modExp(4, odd, mod)) % mod;

    }
};