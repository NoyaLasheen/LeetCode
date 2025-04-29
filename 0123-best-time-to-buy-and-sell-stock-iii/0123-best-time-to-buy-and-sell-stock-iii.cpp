class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> leftProf(n, 0), rightProf(n, 0);
        int maxProf = 0;

        int least = prices[0], most = prices[n - 1];
        for (int i = 1; i < n; i++) {
            least = min(least, prices[i]);
            leftProf[i] = max(leftProf[i - 1], prices[i] - least);
        }

        for (int i = n - 2; i >= 0; i--) {
            most = max(most, prices[i]);
            rightProf[i] = max(rightProf[i + 1], most - prices[i]);
        }

        for (int i = 0; i < n; i++) {
            maxProf = max(maxProf, leftProf[i] + rightProf[i]);
        }
        return maxProf;
    }
};