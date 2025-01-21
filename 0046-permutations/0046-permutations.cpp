class Solution {
    vector<vector<int>> ans;
    void generate(vector<int>& nums, int i, int n) {
        if (i == n) {
            ans.push_back(nums);
            return;
        } 

        for (int j = i; j < n; j++) {
            swap(nums[i], nums[j]);
            generate(nums, i + 1, n);
            swap(nums[i], nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        generate(nums, 0, nums.size());
        return ans;
    }
};