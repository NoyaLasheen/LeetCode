class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map <int, int> mp;
        int streak = 0, max_streak = 0, num;
        
        for (int i : nums) {
            mp[i]++;
        }
        
        for (int i : nums) {
            if (mp.find(i - 1) == mp.end()) {
                streak = 1;
                num = i;
            }  
            while (mp.find(num + 1) != mp.end()) {
                num++;
                streak++;
            }
            max_streak = max(max_streak, streak);
            
        }
        return max_streak;
    }
};