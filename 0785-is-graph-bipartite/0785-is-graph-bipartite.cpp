class Solution {
    bool check(vector<vector<int>>& graph, vector<vector<int>>& adj, int start, vector<int> color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& nbr : adj[node]) {
                if (color[nbr] == -1) {
                    color[nbr] = !color[node];
                    q.push(nbr);
                } else if (color[nbr] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int nbr : graph[i]) {
                adj[i].push_back(nbr);
                adj[nbr].push_back(i);
            }
        }

        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!check(graph, adj, i, color)) return false;
            }
        }
        return true;
    }
};