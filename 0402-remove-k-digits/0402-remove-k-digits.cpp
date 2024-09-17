#include <string>
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.length()) return "0";
        
        stack<char> st;
        
        string s = "";
        for (char ch : num) {
            while (!st.empty() && st.top() - '0' > ch - '0' && k > 0) {
                st.pop();
                k--;
            }
                st.push(ch);
           
        }
        while(! st.empty() && k > 0) {
            st.pop();
            k--;
        }
        
        if (st.empty()) return "0";
        
      
        while (!st.empty()) {
            s.push_back(st.top());
            st.pop();
        }
        
        // Reverse the string to get the correct order
        reverse(s.begin(), s.end());
        
        int i = 0;
        while (s[i] == '0' && s.substr(i).length() > 1) {
            i++;
        }
        return s.substr(i);
    }
};