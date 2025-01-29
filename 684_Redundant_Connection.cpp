class Solution {
public:
    bool is_connected(vector<set<int>>& adj, int n) {
        vector<bool> visited(n+1, false);
        int cnt = n;
        queue<int> q;

        q.push(1);
        visited[1] = true;
        cnt--;

        while(!q.empty()) {
            int now = q.front();
            q.pop();
            for (auto v: adj[now]) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                    cnt--;
                }
            } 
        }

        return cnt == 0;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<set<int>> adj(n+1);
        vector<int> ans;

        int a, b;
        for (int i = 0; i < n ; i++) {
            a = edges[i][0];
            b = edges[i][1];
            adj[a].insert(b);
            adj[b].insert(a);
        } 

        for (int i = n - 1; i >= 0; i--) {
            a = edges[i][0];
            b = edges[i][1];

            // prune one edge
            adj[a].erase(b);
            adj[b].erase(a);

            if (adj[a].size()==0 || adj[b].size()==0) {
                // restore
                adj[a].insert(b);
                adj[b].insert(a);
                continue;
            }

            if (is_connected(adj, n)) {
                ans.push_back(a);
                ans.push_back(b);
                break;
            }

            // restore
            adj[a].insert(b);
            adj[b].insert(a);
        }

        return ans;
    }
};
