class Solution {
    int mem[100001];
    int MOD = 1000000007;

    int countWays(int low, int high, int zero, int one, int pos) {
        if (pos > high) return 0;
        if (mem[pos] != -1) return mem[pos];

        int count = 0;
        if (pos >= low) count++;
        count += countWays(low, high, zero, one, pos + zero);
        count += countWays(low, high, zero, one, pos + one);
        
        return mem[pos] = count % MOD;
    }

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(mem, -1, sizeof(mem));
        return countWays(low, high, zero, one, 0);
    }
};