class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> connect_num(n);
        for (int i = 0; i < n; i++) {
            connect_num[i] = adj[i].size();
        }

        queue<int> q;
        int total = n;
        for (int i = 0; i < n; i++) {
            if (connect_num[i] == 1) {
                q.push(i);
            }
        }

        while (n > 2) {
            int size = q.size();
            n -= size;

            for (int i = 0; i < size; i++) {
                int now = q.front();
                q.pop();

                for (auto& neighbor : adj[now]) {
                    connect_num[neighbor]--;
                    if (connect_num[neighbor] == 1) q.push(neighbor);
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};
