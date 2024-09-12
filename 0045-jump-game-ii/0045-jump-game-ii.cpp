class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0, maxReach = 0, lastJump = 0, jumps = 0;
        
        while (i < nums.size() - 1) {
            maxReach = max(maxReach, i + nums[i]);
            if (i == lastJump) {
                jumps++;
                lastJump = maxReach;    
            }

            if (i < lastJump) i++;
        }
        return jumps;
    }
};