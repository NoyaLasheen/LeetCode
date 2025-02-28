class Solution {
    void findComb(vector<int>& candidates, vector<int>& curr, int idx,
                  int target, vector<vector<int>>& ans) {
        if (idx == candidates.size()) {
            if (target == 0)
                ans.push_back(curr);
            return;
        }

        if (candidates[idx] <= target) {
            curr.push_back(candidates[idx]);
            findComb(candidates, curr, idx, target - candidates[idx], ans);
            curr.pop_back();
        }
        findComb(candidates, curr, idx + 1, target, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        findComb(candidates, curr, 0, target, ans);
        return ans;
    }
};
//