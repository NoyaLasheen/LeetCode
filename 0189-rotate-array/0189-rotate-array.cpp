class Solution {
public:
    void reverse(vector<int>& arr, int start, int end) {
        int temp;
        while (start < end) {
            temp = arr[start];
            arr[start] = arr[end - 1];
            arr[end - 1] = temp;
            start++;
            end--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        if (k == 0 || k == nums.size() || nums.size() == 0 || nums.size() == 1) return;
        int x = k % nums.size();
        reverse(nums, 0, nums.size());
        reverse(nums, 0, x);
        reverse(nums, x, nums.size());
    }
};