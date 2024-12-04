class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        
        
        int m = str1.length();
        int n = str2.length();
        
        if (n > m) return false;
        if (str1 == str2) return true;
        
        int i = 0, j = 0;
        
        while (i < m && j < n) {
            if (str1[i] == str2[j]) {
                i++, j++;
            } else if ((str1[i] + 1 == str2[j]) || (str1[i] == 'z' && str2[j] == 'a')) {
                i++, j++;
            } else {
                i++;
            } 
        }
        if (i == m && j < n) 
            return false;
        else 
            return true;

    }
};