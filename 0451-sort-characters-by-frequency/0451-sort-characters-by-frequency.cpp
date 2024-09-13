class Solution {
public:
    string frequencySort(string s) {
        
        string ans;
        
        unordered_map <char, int> mp;
        
        for (char ch : s) mp[ch]++;
        
        int maxFreq = 0;
        int maxChar = ' ';
        
        for (int i = 0; i < mp.size(); i++) {
            for (auto &pair : mp) {
                if (pair.second > maxFreq) {
                    maxFreq = pair.second;
                    maxChar = pair.first;
                }
            }
            while (maxFreq > 0) {
                ans += maxChar;   
                maxFreq--;
            }
            mp[maxChar] = 0;
        }
        
        return ans;    
                           
               
        
    }
};