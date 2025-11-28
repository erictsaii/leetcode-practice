class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if (n == 1) return 1;
        vector<unordered_set<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1) q.push(i);
        }

        int ans = 0;
        while (q.size()) {
            int curr_node = q.front();
            q.pop();

            if (values[curr_node] % k == 0) {
                ans++;
            }
            else {
                auto it = adj[curr_node].begin();
                values[*it] += values[curr_node];
                values[*it] %= k;
            }

            for (auto& neighbor : adj[curr_node]) {
                adj[neighbor].erase(curr_node);
                if (adj[neighbor].size() == 1) q.push(neighbor);
            }
        }
        return ans;
    }
};


// TODO:
// first, build a adjacent list to represent the whole graph 

// using topological order (but with connected_num == 1)
// first, it'll check the val itself
// if it's divisible by k, ans++
// if it's not, add curr val to its neighbor (the only connected neighbor)
// remember to update the connected_num of neighbor
// O(n)
