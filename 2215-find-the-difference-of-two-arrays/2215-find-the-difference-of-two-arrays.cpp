class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        
    
        vector<vector<int>> difference(2);
        
        for (int i : s1) {
            if (s2.find(i) == s2.end()) {
                difference[0].push_back(i);
            }            
        }
        
        for (int i : s2) {
            if (s1.find(i) == s1.end()) {
                difference[1].push_back(i);
            }
        }
        
        return difference;
    }
};