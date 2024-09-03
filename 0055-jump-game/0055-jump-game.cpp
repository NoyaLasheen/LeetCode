class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = nums.size() - 2;
        int end = nums.size() - 1;
        
        while (i >= 0) {
            if (i + nums[i] >= end) end = i;
            i--;            
        }
        return end == 0;
    }
    
};