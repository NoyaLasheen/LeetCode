class Solution {
public:
    bool isAnagram(string s, string t) {
        
           if (s.length() != t.length()) return false;
//         map<char, int> mp;
        
//         for (int i = 0; i < s.length(); i++) {
//             mp[s[i]]++;
//             mp[t[i]]--;
//         }
//         for (auto &pair : mp) {
//             if (pair.second != 0) return false;
//         }
//         return true;
        
        int arr[52];
        
        for (int i = 0; i < s.length(); i++) {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        
        for (int i : arr) {
            if (i != 0) return false; 
            // cout << i << " ";
        }
        return true;
    }
};