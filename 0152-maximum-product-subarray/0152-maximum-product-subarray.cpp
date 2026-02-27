class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minProd = nums[0];
        int maxProd = nums[0];
        int globalMax = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int prevMin = minProd, prevMax = maxProd;
            minProd = min(nums[i],
              min(prevMin * nums[i], prevMax * nums[i]));
            maxProd = max(nums[i],
              max(prevMin * nums[i], prevMax * nums[i]));
            globalMax = max(globalMax, maxProd);
        }
        return globalMax;
    }
};