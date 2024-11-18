class Solution {
public:
    void calcSum(vector<int>& res, int k, vector<int>& prefix) {
        int n = res.size();
        
        if (k > 0) {
            for (int i = 0; i < n; i++) {
                res[i] = prefix[i + k] - prefix[i];
            }
        } else {
            k = abs(k);
            for (int i = n; i < 2 * n; i++) {
                res[i - n] = prefix[i - 1] - prefix[i - k - 1];
            }
        }
    }
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        
        if (k == 0) {
            return vector<int>(n, 0);
        }
        
        vector<int> prefix(2 * n);
        prefix[0] = code[0];
        
        for (int i = 1; i < n * 2; i++) {
            prefix[i] = prefix[i - 1] + code[i % n];          
        }
        
        vector<int> res(n);
        calcSum(res, k, prefix);
        
        return res;
    }
};