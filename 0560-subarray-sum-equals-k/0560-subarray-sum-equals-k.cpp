class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        if (nums.size() == 0) return 0;
        
        map<int, int> prefix_sum;
        int curr_sum = 0;
        int count = 0;
        
        for (int x : nums) {
            
            curr_sum += x;
            
            if (curr_sum == k) {
                count++;
            }
            
            
            if (prefix_sum.find(curr_sum - k) != prefix_sum.end()) {
                count += prefix_sum[curr_sum-k];
            }
            prefix_sum[curr_sum]++;
        }
        
        return count;
    }
};