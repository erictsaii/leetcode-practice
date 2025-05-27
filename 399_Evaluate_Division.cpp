class Solution {
public:
    double result = -1;
    vector<vector<pair<int, double>>> adj;

    void dfs(int now, int target, double sum, vector<bool>& visited) {
        if (now == target) {
            result = sum;
        }
        else {
            for (auto& neighbor : adj[now]) {
                if (!visited[neighbor.first]) {
                    visited[neighbor.first] = true;
                    dfs(neighbor.first, target, sum*neighbor.second, visited);
                }
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int size = 0;
        unordered_map<string, int> m;

        // 編號
        for (auto& equation : equations) {
            if (m.find(equation[0]) == m.end()) {
                m[equation[0]] = size++;
            }
            if (m.find(equation[1]) == m.end()) {
                m[equation[1]] = size++;
            }
        }

        // build adj list
        adj.resize(size);
        for (int i = 0; i < equations.size(); i++) {
            int u = m[equations[i][0]];
            int v = m[equations[i][1]];
            adj[u].push_back({v, values[i]});
            adj[v].push_back({u, 1/values[i]});
        }

        // output ans
        vector<double> ans;
        for (auto& q : queries) {
            if (m.find(q[0]) == m.end() || m.find(q[1]) == m.end()) {
                ans.push_back(-1.0);
            }
            else if (q[0] == q[1]) {
                ans.push_back(1.0);
            }
            else {
                vector<bool> visited(size, false);
                int u = m[q[0]];
                int v = m[q[1]];
                result = -1;
                dfs(u, v, 1, visited);
                ans.push_back(result);
            }
        }
        
        return ans;
    }
};