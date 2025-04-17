class Solution {
    void generate(vector<vector<int>>& ans, vector<int>& curr, int& sum, int k, int n, int i) {
        if (curr.size() == k && sum == n) ans.push_back(curr);

        for (int idx = i + 1; idx <= 9; idx++) {
            curr.push_back(idx);
            sum += idx;
            generate(ans, curr, sum, k, n, idx);
            curr.pop_back();
            sum -= idx;
        }

        if (sum > n || curr.size() > k) return;
    } 
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        int sum = 0;
        generate(ans, curr, sum, k, n, 0);
        return ans;
    }
};