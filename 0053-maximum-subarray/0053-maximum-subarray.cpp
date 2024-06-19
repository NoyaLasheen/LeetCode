class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int c_sum = 0;
        int neg = 0;
        int max_sum = INT_MIN;
        for (int i = 0; i< nums.size(); i++){
            c_sum += nums[i];
            if(nums[i] < 0) {
                neg++;
            }
            if (c_sum < 0) {
                c_sum = 0;
            }
            max_sum = max(c_sum, max_sum);
        }
        if(neg == nums.size()) {
            return *max_element(nums.begin(), nums.end());
        }
        return max_sum;
    }
    
};