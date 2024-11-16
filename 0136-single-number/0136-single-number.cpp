class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int single = 0;
        
        for (int i : nums) single = single ^ i;
        
        return single;
    }
};