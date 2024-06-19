class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int c_sum = 0;
        // int neg = 0;
        int max_sum = INT_MIN;
        for (int i = 0; i< nums.size(); i++){
            c_sum = max(nums[i], c_sum + nums[i]);
            max_sum = max(c_sum, max_sum);
        }
        return max_sum;       
            
            
    }
    
    
};