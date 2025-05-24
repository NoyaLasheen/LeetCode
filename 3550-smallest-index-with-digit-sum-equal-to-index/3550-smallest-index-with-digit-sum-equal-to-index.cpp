class Solution {
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (i == digitSum(nums[i])) return i;
        }

        return -1;
    }
};