class Solution {
public:
    int minAddToMakeValid(string s) {
        int left_open = 0, right_open = 0;
        for (char ch : s) {
            if (ch == '(') {
                left_open++;
            } else {
                if (left_open == 0) {
                    right_open++;
                } else {
                    left_open--;
                }
            }
        }
        
        return right_open + left_open;
    }
};