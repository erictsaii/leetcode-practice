class Solution {
public:
    vector<int> parent;
    vector<int> depth;

    int find(int root) {
        if (parent[root] == -1) return root;
        return parent[root] = find(parent[root]);
    }

    void join(int root1, int root2) {
        int p1 = find(root1);
        int p2 = find(root2);
        if (p1 == p2) return;

        if (depth[p1] > depth[p2]) {
            parent[p2] = p1;
        }
        else if (depth[p1] < depth[p2]) {
            parent[p1] = p2;
        }
        else {
            parent[p2] = p1;
            depth[p1]++;
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        parent.assign(c+1, -1);
        depth.assign(c+1, 0);

        for (auto& connection : connections) {
            join(connection[0], connection[1]);
        }

        unordered_map<int, set<int>> m; // parent_num, set
        for (int i = 1; i <= c; i++) {
            int p = find(i);
            m[p].insert(i);
        }

        vector<int> ans;
        for (auto& q : queries) {
            int p = find(q[1]);

            if (q[0] == 1) {
                if (m[p].count(q[1])) ans.push_back(q[1]);
                else if (m[p].size()) ans.push_back(*m[p].begin());
                else ans.push_back(-1);
            }
            else {
                m[p].erase(q[1]);
            }
        }
        return ans;
    }
};

// union find
// build the graph through union find and then maintain a set for each parent
