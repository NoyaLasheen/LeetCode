class Solution {
public:
    long long minSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> NSE(n, 0);
        vector<int> PSEE(n, 0);
        stack<int> stn;
        stack<int> stp;
        long long sum = 0;
        
    
        for (int i = n - 1; i >= 0; i--) {
            while (!stn.empty() && nums[stn.top()] > nums[i]) {
                stn.pop();
            }
            NSE[i] = stn.empty() ? n : stn.top();
            stn.push(i);
        } 
        
        
        for (int i = 0; i < n; i++) {
            while (!stp.empty() && nums[stp.top()] >= nums[i]) {
                stp.pop();
            }
            PSEE[i] = stp.empty() ? -1 : stp.top();
            stp.push(i);
        }
        
        
        for (int i = 0; i < n; i++) {
            long long left = i - PSEE[i];    
            long long right = NSE[i] - i;    
            long long contribution = left * right * 1LL * nums[i];
            sum += contribution;
        } 
        
        return sum;
    }
    
    long long maxSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> NGE(n, 0);
        vector<int> PGEE(n, 0);
        stack<int> stn;
        stack<int> stp;
        long long sum = 0;
        
        
        for (int i = n - 1; i >= 0; i--) {
            while (!stn.empty() && nums[stn.top()] < nums[i]) {
                stn.pop();
            }
            NGE[i] = stn.empty() ? n : stn.top();
            stn.push(i);
        } 
        
        
        for (int i = 0; i < n; i++) {
            while (!stp.empty() && nums[stp.top()] <= nums[i]) {
                stp.pop();
            }
            PGEE[i] = stp.empty() ? -1 : stp.top();
            stp.push(i);
        }
        
        
        for (int i = 0; i < n; i++) {
            long long left = i - PGEE[i];    
            long long right = NGE[i] - i;    
            long long contribution = left * right * 1LL * nums[i];
            sum += contribution;
        }
        
        return sum;
    }
    
    long long subArrayRanges(vector<int>& nums) {
        return maxSum(nums) - minSum(nums);
    }
};
