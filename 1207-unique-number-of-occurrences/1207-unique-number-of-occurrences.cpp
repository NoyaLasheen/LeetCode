class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map <int, int> frequency;        
        for (int num : arr) frequency[num]++;
        
        unordered_set<int> freq_set;        
        for (auto [key, value] : frequency) freq_set.insert(value);
        
        return frequency.size() == freq_set.size();
    }
};