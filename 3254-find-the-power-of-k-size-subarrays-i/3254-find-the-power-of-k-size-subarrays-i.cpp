class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
       
        deque<int> dq;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            if (! dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            while (! dq.empty() && nums[dq.back()] != nums[i] - 1) {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            if (i >= k - 1) {
                if (dq.size() == k) {
                    result.push_back(nums[dq.back()]);
                } else {
                    result.push_back(-1);
                }
            }
        }
        
        return result;
    }
};