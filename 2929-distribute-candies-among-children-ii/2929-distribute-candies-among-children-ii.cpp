class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;

        for (int i = 0; i <= min(n, limit); i++) {
            int start = max(0, n - i - limit);
            int end = min(limit, n - i);
            if (start <= end) ans += (end - start + 1);
        }

        return ans;
    }
};