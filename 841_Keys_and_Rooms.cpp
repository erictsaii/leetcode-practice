class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> to_be_enter;
        vector<bool> visited(n, false);

        to_be_enter.push(0);
        visited[0] = true;

        while (!to_be_enter.empty()) {
            int now = to_be_enter.front();
            to_be_enter.pop();
            for (auto& key : rooms[now]) {
                if (!visited[key]) to_be_enter.push(key);
                visited[key] = true;
            }
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) return false;
        }
        return true;
    }
};