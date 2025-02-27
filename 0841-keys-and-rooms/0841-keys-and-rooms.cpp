class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> keys;
        keys.insert(0);
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int nxt = q.front();
            q.pop();
            for (int i = 0; i < rooms[nxt].size(); i++) {
                if (keys.find(rooms[nxt][i]) == keys.end()) {
                    keys.insert(rooms[nxt][i]);
                    q.push(rooms[nxt][i]);
                }
            }
        }
        return keys.size() == rooms.size();
    }
};