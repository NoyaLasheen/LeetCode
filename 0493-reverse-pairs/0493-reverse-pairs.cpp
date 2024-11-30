class Solution {

    int merge_sort(vector<int>& arr, int low, int high) {
        
        int count = 0;
        
        if (low >= high) return count;
        
        int mid = (low + high) / 2;
        
        count += merge_sort(arr, low, mid);
        count += merge_sort(arr, mid + 1, high);
        count += count_pairs(arr, low, mid, high);
        merge(arr, low, mid, high);
        
        return count;
    }
    
    void merge(vector<int>& arr, int low, int mid, int high) {
        
        vector<int> temp;
        int i = low, j = mid + 1;
        
        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
            }
        }
        
        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= high) temp.push_back(arr[j++]);
        
        for (int i = low; i <= high; i++) arr[i] = temp[i - low];
    }
    
    int count_pairs(vector<int>& arr, int low, int mid, int high) {
        int count = 0;
        int right = mid + 1;

        for (int i = low; i <= mid; i++) {
            
            while (right <= high && (long long)arr[i] > 2LL * arr[right]) {
                right++;
            }
            count += (right - (mid + 1));
        }
        return count;
    }
    
public:
    
    int reversePairs(vector<int>& nums) {
        return merge_sort(nums, 0, nums.size() - 1);         
    }
};