class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue <long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        int count = 0;
        long long a, b;
        while (pq.size() >= 2 && pq.top() < k) {
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            pq.push(2 * min(a, b) + max(a, b));
            count++;
        }
        return count;
    }
};