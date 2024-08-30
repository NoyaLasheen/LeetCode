#include <algorithm>
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        
        while (left < right) {
        if(!iswalnum(s[left])) {
                left++;
        }else if (!iswalnum(s[right])) {
                right--;
            } else if (tolower(s[right]) != tolower(s[left])) {
                return false;
            } else {
            left++;
            right--;
        }
        }
        return true;
        
        
    }
};