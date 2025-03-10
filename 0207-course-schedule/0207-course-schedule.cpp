class Solution {   
    bool dfsCheck(int node, vector<vector<int>>& adj, vector<int>visited, vector<int>pathVisited) {
        visited[node] = 1;
        pathVisited[node] = 1;

        for (auto& nbr : adj[node])  {
            if (!visited[nbr] && !pathVisited[nbr]) {
                if (!dfsCheck(nbr, adj, visited, pathVisited)) return false;
            } else if (visited[nbr] && pathVisited[nbr]) return false;
        }
        pathVisited[node] = 0;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);

        for (auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!dfsCheck(i, adj, visited, pathVisited)) return false;
            }
        }
        return true;
    }
};