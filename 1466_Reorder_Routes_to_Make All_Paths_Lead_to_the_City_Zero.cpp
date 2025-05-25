class Solution {
public:
    int ans = 0;
    void dfs(int now, vector<vector<pair<int, int>>>& adj, vector<bool>& visited) {
        for (auto& neighbor : adj[now]) {
            if (!visited[neighbor.first]) {
                visited[neighbor.first] = true;
                if (neighbor.second == 1) ans++;
                dfs(neighbor.first, adj, visited);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        vector<bool> visited(n, false);

        for (auto& connection : connections) {
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }

        visited[0] = true;
        dfs(0, adj, visited);

        return ans;
    }
};