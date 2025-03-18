class Solution {
    void generate(vector<int>& candidates, int target, int idx, vector<int>& curr,vector<vector<int>>& ans) {
        
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;

            curr.push_back(candidates[i]);
            generate(candidates, target - candidates[i], i + 1, curr, ans);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        generate(candidates, target, 0, curr, ans);
        return ans;
    }
};