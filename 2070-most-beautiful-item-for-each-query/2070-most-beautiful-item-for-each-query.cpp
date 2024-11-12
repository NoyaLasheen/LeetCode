class Solution {
public:
    int binarySearch(vector<vector<int>>& items, int price) {
        
        int l = 0;
        int h = items.size() - 1;
        int max_beau = 0;
        int mid;
        
        while (l <= h) {
            mid = l + (h - l) / 2;
            if (items[mid][0] <= price) {
                max_beau = max(max_beau, items[mid][1]);
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        
        return max_beau;
    }
    
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        int n = items.size();
        vector<int> res;
        
        sort(items.begin(), items.end());
        
        for (int i = 1; i < n; i++) {
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }
        
        for (int i = 0; i < queries.size(); i++) {
            int ans = binarySearch(items, queries[i]);
            res.push_back(ans);
        }
        
        return res;
    }
};