class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        vector<int> keyInd;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == key) keyInd.push_back(i);
        }

        for (int i = 0; i < n; i++) {
            for (int j : keyInd) {
                if (abs(i - j) <= k) {
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};