class Solution {
    void generate(int idx, vector<int>& nums, vector<int>& current, vector<vector<int>>& result, int n) {
        if (idx >= n) {
            result.push_back(current);
            return;
        } 
        current.push_back(nums[idx]);
        generate(idx + 1, nums, current, result, n);
        current.pop_back();
        generate(idx + 1, nums, current, result, n);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> result;
        int n = nums.size();
        generate(0, nums, current, result, n);
        return result;
    }
};