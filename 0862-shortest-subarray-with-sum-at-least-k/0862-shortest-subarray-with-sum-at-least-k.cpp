class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
//         int n = nums.size();
//         deque<pair<int, int>> dq;
//         long long sum = 0;
//         long long shortest = INT_MAX;
        
//         for (long long i = 0; i < n; i++) {
//             sum += nums[i];
            
//             if (sum >= k) {
//                shortest = min(shortest, i + 1); 
//             } 
            
//             pair<long long, long long> curr = {INT_MIN, INT_MIN};
//             while (! dq.empty() && (sum - dq.front().second >= k)) {
//                 curr = dq.front();
//                 dq.pop_front();
//             }
            
//             if (curr.second != INT_MIN) {
//                 shortest = min(shortest, (i - curr.first));
//             }
            
//             while (!dq.empty() && sum <= dq.back().second) {
//                 dq.pop_back();
//             }
//             dq.push_back({i, sum});
//         }
//         return shortest == INT_MAX ? -1 : shortest;
        
        int n = nums.size();
        deque<pair<int, long long>> dq; 
        long long sum = 0;
        int shortest = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            sum += nums[i];

            
            if (sum >= k) {
                shortest = min(shortest, i + 1); 
            }

            
            while (!dq.empty() && (sum - dq.front().second >= k)) {
                shortest = min(shortest, i - dq.front().first);
                dq.pop_front();
            }

            
            while (!dq.empty() && dq.back().second >= sum) {
                dq.pop_back();
            }

           
            dq.push_back({i, sum});
        }

        return shortest == INT_MAX ? -1 : shortest;
        
    }
};