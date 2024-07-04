class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0, maxCount;
        
        string str = "aeiou";
        
        
        for (int i = 0; i < k; i++) {
            if (str.find(s[i]) != string::npos) {
                count++;
            }
            
            
        }
        maxCount = count;
        
        for (int i = k; i < s.length(); i++) {
            if (str.find(s[i - k]) != string::npos) {
                count--;
            }
            if (str.find(s[i]) != string::npos) {
                count++;
            }
                    
                        
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }
};