class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> time(n + 1, INT_MAX);
        int count = 0;
        int max_time = 0;
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto &edge : times) {
            int u = edge[0];
            int v = edge[1];
            int d = edge[2];

            adj[u].push_back({d, v});
        }

        time[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            int t = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (t > time[node]) continue;
            
            count++;
            max_time = max(max_time, t);

            for (auto& [w, nbr] : adj[node]) {
                int newTime = t + w;
                if (newTime < time[nbr]) {
                    time[nbr] = newTime;
                    pq.push({newTime, nbr});
                }
            }
        }

        return count == n ? max_time : -1;
    }
};