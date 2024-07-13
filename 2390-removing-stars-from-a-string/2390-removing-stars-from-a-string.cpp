class Solution {
public:
    string removeStars(string s) {
        
//         stack <char> stars;
        
//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] != '*') {
//                 stars.push(s[i]);
//             } else {
//                 stars.pop();
//             }
//         }
        
//         string ans;
        
//         while (!stars.empty()) {
//             ans = stars.top() + ans;
//             stars.pop();
//         }
        
//         return ans;
        
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
            
//         
    }
};