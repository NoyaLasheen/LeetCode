class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = (int)(1e9 + 7);
        vector<int> ways(n, 0);
        vector<long long> time(n, LLONG_MAX);
        vector<vector<pair<int, int>>> adj(n);
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        time[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            long long wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (wt > time[node]) continue;

            for (auto& [nbr, t] : adj[node]) {
                if (t + wt < time[nbr]) {
                    time[nbr] = t + wt;
                    ways[nbr] = ways[node];
                    pq.push({t + wt, nbr});
                } else if (t + wt == time[nbr]) {
                    ways[nbr] = (ways[nbr] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};