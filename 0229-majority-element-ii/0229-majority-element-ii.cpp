class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        vector<int> ans;
        
        for (int i : nums) mp[i]++;
        
        for (auto &pair : mp) {
            if (pair.second > nums.size() / 3) {
                ans.push_back(pair.first);
            }
        }
        
        return ans;
        
    }
};