class Solution {
public:
    string decodeString(string s) {
        
        stack <int> num_st;
        stack <string> char_st;
        string ans;
        int num;
        
//         for (char ch : s) {
//             if (isdigit(ch)) {
//                 int num = num * 10 + (ch - '0');
//                 num_st.push(num);
//             } else {
//                 if (ch != ']') {
//                     char_st.push(string(1, ch)); 
//                 } else {
//                     string res;
//                     while (char_st.top() != "[") {
//                         res = char_st.top() + res;
//                         char_st.pop();
//                     }
//                     char_st.pop();
//                     int n = num_st.top();
//                     num_st.pop();
//                     ans = "";
//                     for (int i = 0; i < n; i++) {
//                         ans += res;
//                     }
//                     char_st.push(ans);
                    
//                 }
//             }
//         }
        
        for (char ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else if (ch == '[') {
                num_st.push(num);
                char_st.push(ans);
                num = 0;
                ans = "";
            } else if (ch == ']') {
                string temp = ans;
                ans = char_st.top();
                char_st.pop();
                int n = num_st.top();
                num_st.pop();
                for (int i = 0; i < n; i++) {
                    ans += temp;
                }
                
            } else {
                ans += ch;
            }
        }
        return ans;
    }
};