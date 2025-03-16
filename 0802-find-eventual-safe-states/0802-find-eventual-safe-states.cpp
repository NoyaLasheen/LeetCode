class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0), ans;
        queue<int> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                indeg[i]++;
                adj[graph[i][j]].push_back(i);
            }
        }

        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) q.push(i);
        }

        while (! q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto& nbr : adj[node]) {
                indeg[nbr]--;
                if (indeg[nbr] == 0) q.push(nbr);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};