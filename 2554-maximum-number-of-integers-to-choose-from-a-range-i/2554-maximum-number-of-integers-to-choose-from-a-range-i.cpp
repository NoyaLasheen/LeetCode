class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
        set<int> nums;
        for (int x : banned) {
            nums.insert(x);
        }
        
        int sum = 0, count = 0;
        
        for (int i = 1; i <= n && sum <= maxSum; i++) {
            if (nums.find(i) == nums.end()) {
                if (sum + i > maxSum) break;
                sum += i;
                count++;
            }
        }
        
        return count;
    }
};