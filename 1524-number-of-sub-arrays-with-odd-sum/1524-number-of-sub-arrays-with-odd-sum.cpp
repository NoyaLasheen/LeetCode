class Solution {
    #define MOD 1000000007
public:
    int numOfSubarrays(vector<int>& arr) {
        int oddCount = 0;
        int evenCount = 1;
        int prefixSum = 0;
        int result = 0;

        for (int i : arr) {
            prefixSum += i;
            if (prefixSum % 2) {
                result = (result + evenCount) % MOD;
                oddCount++;
            } else {
                result = (result + oddCount) % MOD;
                evenCount++;
            }
        }
        return result;
    }
};