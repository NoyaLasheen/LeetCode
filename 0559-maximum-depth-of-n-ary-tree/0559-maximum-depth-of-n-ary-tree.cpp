/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        
        int height = 0;
        queue<pair<Node*, int>> q;
        q.push({root, 1});

        while (!q.empty()) {
            Node* node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            height = max(height, level);
            for (int i = 0; i < node->children.size(); i++) {
                q.push({node->children[i], level + 1});
            }
        }
        return height;
    }
};