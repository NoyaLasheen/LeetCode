class Solution {
    
    struct trienode{
        int index;
        unordered_map<char, trienode*> child;
    };
    trienode* root = new trienode;
    
    void insert_trie(string& word, int idx) {
        trienode* curr = root;
        for (int i = 0; word[i]; i++) {
            if (!curr->child.count(word[i])) {
                curr->child[word[i]] = new trienode;
                curr->child[word[i]]->index = idx;
            }
            curr = curr->child[word[i]];
        }
    }
    
    int search_trie(string& word) {
        trienode* curr = root;  
        for (int i = 0; word[i]; i++) {
            if (!curr->child.count(word[i])) 
                return -1;
            curr = curr->child[word[i]];
        }
        return curr->index;
    }
    
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size();
        int idx = 1;
        
        for (int i = 0; i < n; i++) {
            string word = "";
            while (i < n && sentence[i] != ' ') {
                word.push_back(sentence[i]);
                i++;
            }
            insert_trie(word, idx);
            idx++;
        }
        
        return search_trie(searchWord);
    }
};