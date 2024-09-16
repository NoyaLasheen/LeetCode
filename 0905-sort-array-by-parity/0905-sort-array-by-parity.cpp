class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> even, odd;
        
        for (int i : nums) {
            if (i % 2 == 0) even.push_back(i);
            else odd.push_back(i);
        }
        
        int i = 0;
        
        for (int j : even) nums[i++] = j;
        for (int j : odd) nums[i++] = j;
        
        return nums;
        
    }
};