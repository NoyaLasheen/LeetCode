class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {};
        int score = 0; 
    };
    
    class Trie {
    public:
        TrieNode* root;
        
        Trie() {
            root = new TrieNode();
        }
        
        void insert(const string& word) {
            TrieNode* node = root;
            for (char c : word) {
                if (!node->children[c - 'a']) {
                    node->children[c - 'a'] = new TrieNode();
                }
                node = node->children[c - 'a'];
                node->score++;
            }
        }
        
        int getScore(const string& word) {
            TrieNode* node = root;
            int sum = 0;
            for (char c : word) {
                node = node->children[c - 'a'];
                sum += node->score;
            }
            return sum;
        }
    };
    
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        vector<int> ans;
        
       
        for (const string& word : words) {
            trie.insert(word);
        }
        
        
        for (const string& word : words) {
            ans.push_back(trie.getScore(word));
        }
        
        return ans;
    }
};
