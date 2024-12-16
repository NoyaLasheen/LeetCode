class Solution {
    #define pr pair<int, int>
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pr, vector<pr>, greater<pr>> minheap;
        
        for (int i = 0; i < nums.size(); i++) {
            minheap.push({nums[i], i});
        }
        
        while (k--) {
            pr vals = minheap.top();
            minheap.pop();            
            vals.first *= multiplier;
            nums[vals.second] = vals.first;
            minheap.push(vals);
        }
        return nums;
    }
};