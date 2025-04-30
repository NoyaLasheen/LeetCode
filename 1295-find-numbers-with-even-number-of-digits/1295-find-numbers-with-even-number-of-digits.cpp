class Solution {
    int countDigits(int n) {
        int count = 0;
        while (n > 0) {
            n /= 10;
            count++;
        }
        return count;
    }
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (countDigits(nums[i]) % 2 == 0) {
                count++;
            }
        }
        return count;
    }
};