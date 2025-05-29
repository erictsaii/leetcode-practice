class Solution {
public:
    void dfs(int now, int& odd, int& even, int depth, vector<bool>& visited, vector<vector<int>>& adj) {
        if (depth % 2) odd++;
        else even++;
        for (auto& neighbor : adj[now]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                dfs(neighbor, odd, even, depth+1, visited, adj);
            }
        }
    }
    void record(int now, int odd, int even, vector<vector<int>>& adj1, vector<int>& ans) {
        for (auto& neighbor : adj1[now]) {
            if (ans[neighbor] == 0) {
                ans[neighbor] = odd;
                record(neighbor, even, odd, adj1, ans);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1, m = edges2.size()+1;
        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(m);

        // build adj
        for (auto& e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        // count node 0's target number (tree 1)
        int odd = 0, even = 0;
        vector<bool> visited(n, false); 
        visited[0] = true;
        dfs(0, odd, even, 0, visited, adj1);

        // traverse all nodes (tree 1)
        visited.resize(n, false);
        vector<int> ans(n, 0);
        ans[0] = even;
        record(0, odd, even, adj1, ans);

        // count node 0's target number (tree 2)
        odd = 0, even = 0;
        visited.assign(m, false);
        visited[0] = true;
        dfs(0, odd, even, 0, visited, adj2);

        int x = max(odd, even);

        for (int i = 0; i < n; i++) ans[i] += x;

        return ans;
    }
};

// 0
// odd:  1 2
// even: 0 3 4

// 2
// odd: 0 3 4
// even: 1 2

// 1
// odd: 0 3 4
// even: 1 2

// 4
// odd:  1 2
// even: 0 3 4
