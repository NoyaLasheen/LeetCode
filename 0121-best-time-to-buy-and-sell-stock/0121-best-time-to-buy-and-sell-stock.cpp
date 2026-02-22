class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minCost = prices[0];
        int maxProf = 0;

        for (int i = 1; i < prices.size(); i++) {
            maxProf = max (maxProf, prices[i] - minCost);
            minCost = min(minCost, prices[i]);
        }

        return maxProf;
    }
};