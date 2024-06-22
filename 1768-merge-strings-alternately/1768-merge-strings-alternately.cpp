class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int i = 0, j = 0;
        
        string m = "";
        
        while((i < word1.length()) && (j < word2.length())) {
            m += word1[i++];
            m += word2[j++];
        }
        
        while(i < word1.length()) {
            m += word1[i++];
        }
        
        while(j < word2.length()) {
            m += word2[j++];
        }
        
        return m;
    }
    
};