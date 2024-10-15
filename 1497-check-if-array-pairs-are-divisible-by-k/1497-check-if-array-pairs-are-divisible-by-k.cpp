class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        
        for (int i : arr) {
            int rem = i % k;
            if (rem < 0) {
                mp[rem + k]++;
            } else {
                mp[rem]++;
            }
        }
        
        for (auto &[rem, count] : mp) {
            if (rem == 0) {
                if (count % 2 != 0) {
                    return false;
                }
            } else {
                if (mp[rem] != mp[k - rem]) {
                    return false;
                }
            }
             
        }
        
        return true;
    }
};