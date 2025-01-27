class Solution {
    # define ll long long
    ll MOD = 1e9+7;
public:
    int countHousePlacements(int n) {
        vector<vector<ll>> dp(n + 1, vector<ll>(2));
        dp[0][0] = 1;
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            dp[i][1] = dp[i - 1][0];
        }

        ll ans = (dp[n][0] + dp[n][1]) % MOD;
        return (ans * ans) % MOD;
    }
};