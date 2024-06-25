class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        
        int smallest = INT_MAX;
        int smallest2 = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < smallest) {
                smallest = nums[i];
            } else if (nums[i] < smallest2 && nums[i] > smallest) {
                smallest2 = nums[i];
            } else if (nums[i] > smallest2) {
                return true;
            }
        }
        return false;
        
    }
};