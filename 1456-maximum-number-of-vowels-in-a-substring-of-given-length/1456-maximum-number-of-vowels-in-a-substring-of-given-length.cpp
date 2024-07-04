class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0, maxCount;
        
        // string str = "aeiouAEIOU";
        unordered_set<char> vowelSet;
        vowelSet.insert('a'); vowelSet.insert('e'); vowelSet.insert('i'); 
        vowelSet.insert('o'); vowelSet.insert('u');
        
        for (int i = 0; i < k; i++) {
            // if (str.find(s[i]) != string::npos) {
            //     count++;
            // }
            
            if (vowelSet.find(s[i]) != vowelSet.end()) {
                count++;
            }
        }
        maxCount = count;
        
        for (int i = k; i < s.length(); i++) {
            // if (str.find(s[i - k]) != string::npos) {
            //     count--;
            // }
            // if (str.find(s[i]) != string::npos) {
            //     count++;
            // }
            
            if (vowelSet.find(s[i - k]) != vowelSet.end()) {
                count--;
            }
            
            if (vowelSet.find(s[i]) != vowelSet.end()) {
                count++;
            }
            
            
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }
};