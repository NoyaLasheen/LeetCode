class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 2) return {0, 1};

        unordered_map <int, int> mp;
        for (int i = 0; i < n; i++) {
            int comp = target - nums[i];
            if (mp.find(comp) != mp.end()) 
                return {mp[comp], i};
            else 
                mp[nums[i]] = i;
        }

        return {};
    }
};