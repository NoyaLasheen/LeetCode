class Solution {
    void generate(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans, int idx) {
        ans.push_back(curr);

        for (int i = idx; i < nums.size(); i++) {
            if (i != idx && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            generate(nums, curr, ans, i + 1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<vector<int>> ans;
        generate(nums, curr, ans, 0);
        return ans;
    }
};