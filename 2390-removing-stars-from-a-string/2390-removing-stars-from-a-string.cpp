class Solution {
public:
    string removeStars(string s) {
        int star = 0;
        
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '*') {
                star++;
                s.erase(i, 1);
            } else {
                if (star > 0) {
                    s.erase(i, 1);
                    star--;
                }
            }
        }
        
        return s;
    }
};