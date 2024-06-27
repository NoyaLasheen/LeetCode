class Solution {
    public void moveZeroes(int[] nums) {
        int j = 0, i = 0;
        
        while (j < nums.length) {
            if (nums[j] != 0) {
                nums[i++] = nums[j];
            }
            j++;
        }
        
        while (i < nums.length) {
            nums[i++] = 0;
        }
    }
}