class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        // if (nums.size() == k) {
        //    return accumulate(nums.begin(), nums.end(), 0) * 1.0 / k ;
        // }
        double wSum = 0, maxSum;
        for (int i = 0; i < k; i++) {
            wSum += nums[i];
        }
        
        maxSum = wSum;
        
        for (int i = k; i < nums.size(); i++) {
            wSum = wSum - nums[i - k] + nums[i];
            maxSum = max(maxSum, wSum);
            
        }
        return (maxSum / k);
    }
};