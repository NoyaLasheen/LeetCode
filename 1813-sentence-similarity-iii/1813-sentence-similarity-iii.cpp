class Solution {
public:
    void split(string s, vector<string>& words) {
        string word;
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word.push_back(s[i]);
            }
        }
        words.push_back(word);
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> arr1, arr2;
        split(sentence1, arr1);
        split(sentence2, arr2);
        
        if (arr1.size() > arr2.size()) swap(arr1, arr2);
        
        int l = 0;
        int r1 = arr1.size() - 1;
        int r2 = arr2.size() - 1;
        
        while (l < arr1.size() && arr1[l] == arr2[l]) {
            l++;
        }
        
        while (r1 >= l && r2 >= 0 && arr1[r1] == arr2[r2]) {
            r1--;
            r2--;
        }
        
        
        return l > r1;
    }
};