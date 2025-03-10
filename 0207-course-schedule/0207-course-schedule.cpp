class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int count = 0;

        while (! q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (auto& nbr : adj[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) q.push(nbr);
            }
        }
        return count == numCourses;
    }
};