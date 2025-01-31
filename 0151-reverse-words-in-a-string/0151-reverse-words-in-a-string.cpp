class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                temp += s[i];
            }
            if (temp.length() != 0 && (s[i] == ' ' || i == s.length() - 1)) {
                st.push(temp);
                temp = "";
            }
        }
        while (! st.empty()) {
            temp = temp + st.top() + " ";
            st.pop();
        }
        temp.pop_back();
        return temp;
    }
};