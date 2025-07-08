class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {src, 0}});
        vector<int> minStops(n, INT_MAX);

        while (!pq.empty()) {
            int cost = pq.top().first;
            int node = pq.top().second.first;
            int stop = pq.top().second.second;
            pq.pop();

            if (stop > k + 1) continue;

            if (node == dst) return cost;

            if (stop >= minStops[node]) continue;  

            minStops[node] = stop;

            for (auto& [v, cost2] : adj[node]) {
                pq.push({cost + cost2, {v, stop + 1}});
            }
        }
        return -1;
    }
};