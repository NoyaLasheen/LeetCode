class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) 
            return false;
        unordered_map<int,int> freq1, freq2;
        for (int i = 0; i < word1.length(); i++) {
            freq1[word1[i]]++;
            freq2[word2[i]]++;
        }
        
        vector<int> vec1, vec2;
        set<char> char1, char2;
        
        
        
        for (const auto pair : freq1)
            char1.insert(pair.first);
        for (const auto pair : freq2)
            char2.insert(pair.first);
        
        if (char1 == char2) {
            
            for (const auto pair : freq1)
                vec1.push_back(pair.second);
            for (const auto pair : freq2)
                vec2.push_back(pair.second);
            
            sort(vec1.begin(), vec1.end());
            sort(vec2.begin(), vec2.end());

            return vec1 == vec2;
            
        } else {
            return false;
        }     
            
          
        
    }
};