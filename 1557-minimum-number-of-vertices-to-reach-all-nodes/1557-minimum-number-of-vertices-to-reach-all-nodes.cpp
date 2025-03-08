class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> count(n, 0);
        vector<int> res;

        for (int i = 0; i < edges.size(); i++) {
            count[edges[i][1]]++;
        }

        for (int i = 0; i < n; i++) {
            if (count[i] == 0) res.push_back(i);
        }

        return res;
    }
};