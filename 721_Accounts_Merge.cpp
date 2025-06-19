class Solution {
public:
    vector<int> parent;
    vector<int> depth;

    int find(int node) {
        if (parent[node] == -1) return node;
        return parent[node] = find(parent[node]);
    }

    void join(int a, int b) {
        int root1 = find(a);
        int root2 = find(b);
        if (root1 == root2) return;
        if (depth[root1] > depth[root2]) parent[root2] = root1;
        else if (depth[root1] < depth[root2]) parent[root1] = root2;
        else {
            parent[root2] = root1;
            depth[root1]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.assign(n, -1); // at most n accounts
        depth.assign(n, 0);
        unordered_map<string, int> m;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (m.find(accounts[i][j]) == m.end()) {
                    m[accounts[i][j]] = i;
                }
                else {
                    join(i, m[accounts[i][j]]);
                }
            }
        }

        vector<vector<string>> v(n);
        for (auto& mi : m) {
            int root = find(mi.second);
            v[root].push_back(mi.first);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (v[i].size() == 0) continue;
            vector<string> tmp;
            sort(v[i].begin(), v[i].end());
            ans.push_back({accounts[i][0]});
            ans.back().insert(ans.back().end(), v[i].begin(), v[i].end());
        }
        return ans;
    }
};
