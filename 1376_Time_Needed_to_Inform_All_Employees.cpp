class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < manager.size(); i++) {
            if (i == headID) continue;
            adj[manager[i]].push_back(i);
        }

        int ans = 0;
        queue<pair<int, int>> q; // id, time
        q.push({headID, 0});
        while (q.size()) {
            auto [curr_id, curr_time] = q.front();
            q.pop();

            ans = max(ans, curr_time);

            for (auto& neighbor : adj[curr_id]) {
                q.push({neighbor, curr_time + informTime[curr_id]});
            }
        }
        return ans;
    }
};


// a tree -> it's connected and have no cycle
// the head of the tree would be headID
// BFS
