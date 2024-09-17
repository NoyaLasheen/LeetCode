class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
       
        int mod = int(1e9 + 7);
        int n = arr.size();
        int sum = 0;
        
        stack<int> stp;
        stack<int> stn;
        vector<int> NSE(n, 0);
        vector<int> PSEE(n, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            while(!stn.empty() && arr[stn.top()] >= arr[i]) {
                stn.pop();
            } 
            
            NSE[i] = stn.empty() ? n : stn.top();
            stn.push(i);
        }
        
        for (int i = 0; i < n; i++) {
            while(!stp.empty() && arr[stp.top()] > arr[i]) {
                stp.pop();
            } 
            
            PSEE[i] = stp.empty() ? -1 : stp.top();  
            stp.push(i);
        }
        
        for (int i = 0; i < n; i++) {
            int left = i - PSEE[i]; 
            int right = NSE[i] - i;
            
            sum = (sum + (left * right * 1LL * arr[i]) % mod) % mod;
        }
        
        return sum;
        
    }
};