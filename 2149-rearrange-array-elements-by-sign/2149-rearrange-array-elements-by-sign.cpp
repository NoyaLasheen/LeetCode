class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector <int> arr(nums.size());
        int p = 0;
        int n = 1;
        
        for (int i : nums) {
            if (i > 0) {
                arr[p] = i;
                p += 2;
            } else {
                arr[n] = i;
                n += 2;
            }
        }
        
        return arr;
    }
};