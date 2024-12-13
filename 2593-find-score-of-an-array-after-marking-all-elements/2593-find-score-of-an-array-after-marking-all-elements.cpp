class Solution {
    #define ll long long
    #define pr pair<int, int> 
    
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pr, vector<pr>, greater<pr>> minheap;
        unordered_set<int> marked;
        ll sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            minheap.push({nums[i], i});
        }
        
        while (! minheap.empty()) {
            pr curr = minheap.top();
            minheap.pop();
            
            int idx = curr.second;
            
            if (marked.find(idx) == marked.end()) {
                sum += curr.first;
                marked.insert(idx);
                marked.insert(idx + 1);
                marked.insert(idx - 1);
            }
        }        
        return sum;
    }
};