class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count = 0;
        int n = fruits.size();
        vector<int> used(n, 0);
        
        for (int i = 0; i < n; i++) {
            int placed = 0;
            for (int j = 0; j < n; j++) {
                if (!used[j] && baskets[j] >= fruits[i]) {
                    placed = 1;
                    used[j] = 1;
                    break;
                }
            }
            if (placed == 0) count++;
        }
        return count;
    }
};