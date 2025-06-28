class Solution {
    void build(vector<int>& digits, int n, unordered_set<string> &nums, vector<int> &used, string &curr) {
        if (curr.length() == 3) {
            if ((curr.back() - '0') % 2 == 0) nums.insert(curr);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            if (curr.length() == 0 && digits[i] == 0) continue;
            curr += digits[i];
            used[i] = 1;
            build(digits, n, nums, used, curr);
            curr.pop_back();
            used[i] = 0;
        }

    }
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<string> nums;
        int n = digits.size();
        vector<int> used(n, 0);
        string curr = "";
        build(digits, n, nums, used, curr);
        return nums.size();
    }
};