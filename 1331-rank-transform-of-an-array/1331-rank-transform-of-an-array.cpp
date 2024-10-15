class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        // Create set to remove duplicates
        set<int> unique(arr.begin(), arr.end());
        
        // Create map to track ranks
        map<int, int> ranks;
        int rank = 1;
        
        for (int i : unique) {
            ranks[i] = rank++;
        }
        
        vector<int> ans;
        
        for (int i : arr) {
            ans.push_back(ranks[i]);
        }
        
        return ans;
    }
};