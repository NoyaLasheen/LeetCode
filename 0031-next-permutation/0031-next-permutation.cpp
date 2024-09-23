#include<climits>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
       int index = 0, index2 = -1, small = INT_MAX;
       for (int i = nums.size() -2; i > 0; i--) {
            if (nums[i] <nums[i+ 1]) {
                index = i;
                break;
            }
       }
        
        for (int i = index + 1; i < nums.size(); i++) {
            if (nums[i] > nums[index] && nums[i] < small) {
                small = nums[i];
                index2 = i;
            }       
        }
        
        if (index2 == -1) {
            sort(nums.begin(), nums.end());
        } else {
            int temp = nums[index];
            nums[index] = nums[index2];
            nums[index2] = temp;
            sort(nums.begin() + index + 1, nums.end());
        }
    }
};