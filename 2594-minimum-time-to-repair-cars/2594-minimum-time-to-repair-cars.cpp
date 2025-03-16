class Solution {
    bool canRepair(vector<int>& ranks, long long t, int cars) {
        long long totalCars = 0;

        for (int r : ranks) {
            totalCars += sqrt(t / r);
            if (totalCars >= cars) return true;
        }
        return totalCars >= cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1; 
        long long right = (*min_element(ranks.begin(), ranks.end())) * (long long)cars * cars;

        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (canRepair(ranks, mid, cars)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};