class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        priority_queue<int> maxheap(gifts.begin(), gifts.end());
        long long sum = 0;
        
        while (k--) {
            int curr = maxheap.top();
            maxheap.pop();
            maxheap.push(sqrt(curr));
        }
        
        
        while (! maxheap.empty()) {
            sum += maxheap.top();
            maxheap.pop();
        }
        
        return sum;
    }
};