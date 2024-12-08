class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<vector<int>> intervals;
        
        for (auto& event : events) {
            int start = event[0];
            int end = event[1];
            int val = event[2];
            
            intervals.push_back({start, 1, val});
            intervals.push_back({end + 1, -1, val});
        }
        
        sort(intervals.begin(), intervals.end());
        
        int max_sum = 0, max_val = 0;
        
        for (auto& event : intervals) {
            int point = event[0];
            int status = event[1];
            int val = event[2];
            
            if (status == 1) {
                max_sum = max(max_sum, val + max_val);
            } else {
                max_val = max(max_val, val);
            }
        }
        return max_sum;
    }
};