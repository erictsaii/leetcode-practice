using ll = long long;
class Solution {
public:
    void dfs(vector<vector<int>>& adj, int curr, vector<bool>& visited, int& cnt) {
        cnt++;
        for (auto& neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                dfs(adj, neighbor, visited, cnt);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

        // build the graph
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                ll x_diff = bombs[i][0] - bombs[j][0];
                ll y_diff = bombs[i][1] - bombs[j][1];
                if (x_diff*x_diff + y_diff*y_diff <= 1LL*bombs[i][2]*bombs[i][2]) {
                    adj[i].push_back(j);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            vector<bool> visited(n, false);
            visited[i] = true;
            dfs(adj, i, visited, cnt);
            ans = max(ans, cnt);
        }
        return ans;
    }
};

// turn into graph problem
// it would be a directed graph
// try to start from the bombs with in-degree is 0 and do dfs/bfs
// (or just try every bombs)
// O(n^2)
