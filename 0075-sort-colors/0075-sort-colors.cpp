class Solution {
public:
    
    void swap(vector<int> &arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    void sortColors(vector<int>& nums) {
        
        // Brute Force - bubble sort
        // int n = nums.size();
        // for(int i = 0; i<n;i++)
        // {
        //     for(int j = 0; j < n-1;j++)
        // {
        //     if(nums[j+1]<nums[j])
        //     {
        //         int temp = nums[j + 1];
        //         nums[j+1]=nums[j];
        //         nums[j]=temp;
        //     }
        // }
        // }
        
        int start = 0, mid = 0, end = nums.size() - 1;
        
        while (mid <= end) {
            if (nums[mid] == 0) {
                swap(nums, mid, start);
                start++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums, mid, end);
                end--;
            }
        }              
        
    }
};