class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> special;
        int n = nums.size();
        vector<int> prefix(n, 1);
        
        for (int i = 1; i < n; i++) {
            if ((nums[i] & 1) != (nums[i - 1] & 1)) {
                prefix[i] = prefix[i - 1] + 1;
            }
        }
        
        for (auto& query : queries) {
            if (prefix[query[1]] >= query[1] - query[0] + 1) 
                special.push_back(true);
            else 
                special.push_back(false);
        }
        
        return special;
    }
};