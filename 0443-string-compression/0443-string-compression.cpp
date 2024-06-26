// # include <string>
class Solution {
public:
    int compress(vector<char>& chars) {
        
        int index = 0;
        int i = 0;
        
        while (i < chars.size()) {
            int j = i + 1;
            while (j < chars.size() && chars[j] == chars[i]) {
                j++;
            } 
            chars[index++] = chars[i];
            if (j - i > 1) {
                std::string count = std::to_string(j - i);
                for (char c : count) {
                    chars[index++] = c;
                }
            }
            i = j;
            
        }
        
        return index;
        
        
       
    }
};