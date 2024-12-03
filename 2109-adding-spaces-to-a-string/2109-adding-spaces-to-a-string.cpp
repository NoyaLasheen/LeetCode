class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        
        int i = 0, j = 0;
        
        while (i < s.size()) {
            if (j < spaces.size() && i == spaces[j]) {
                res.push_back(' ');
                j++;
            }
            res.push_back(s[i++]);
        }
        
        return res;
    }
};