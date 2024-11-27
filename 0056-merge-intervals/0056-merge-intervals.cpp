class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        
        int n = intervals.size();
        int i = 0;
        
        while (i < n) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            i++;
            
            while (i < n && end >= intervals[i][0]) {
                end = max(end, intervals[i][1]);
                i++;
            }
            
            result.push_back({start, end});
            
        }
        return result;
    }
};