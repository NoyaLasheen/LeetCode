class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int, int> m;
        
        for (int i : nums) 
            m[i]++;
        
        for (auto &pair : m) {
            if (pair.second > nums.size() / 2) return pair.first;
        }
        
        return -1;
    }
};