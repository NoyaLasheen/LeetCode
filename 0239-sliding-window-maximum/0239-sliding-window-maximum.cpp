class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); i++) {
           
            if (! dq.empty() && dq.front() <= i - k) dq.pop_front();
            if (! dq.empty() && dq.back() <= i - k) dq.pop_back();
                
            while (! dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            if (dq.empty()) dq.push_front(i);
            else if (nums[i] > nums[dq.front()]) 
                dq.push_front(i);   
            else 
                dq.push_back(i);
            
            if (i >= k - 1) ans.push_back(nums[dq.front()]);
        }
        
        return ans;
            
    }
};