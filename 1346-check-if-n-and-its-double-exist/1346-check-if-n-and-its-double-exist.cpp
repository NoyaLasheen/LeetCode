class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        map<int, int> hash;
        
        for (int i : arr) {
            
            if (i % 2 == 0) {
                if (hash.find(i / 2) != hash.end()) return true;
            }
            if (hash.find(i * 2) != hash.end()) return true;
            hash[i]++;
        }
        return false;
    }
};