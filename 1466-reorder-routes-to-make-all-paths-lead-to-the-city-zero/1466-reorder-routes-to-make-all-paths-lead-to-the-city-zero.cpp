class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& conn : connections) {
            int u = conn[0], v = conn[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }
        int count = 0;
        queue<int> q;
        vector<int> visited(n, 0);
        q.push(0);
        visited[0] = 1;

        while (!q.empty()) {
            int nxt = q.front();
            q.pop();
            for (auto&[u, v] : adj[nxt]) {
                if (visited[u] == 0) {
                    if (v == 1) count++;
                    q.push(u);
                    visited[u] = 1;
                }
            }
        }
        return count;
    }
};