class Solution {
    public:
        vector<int> parent;
        vector <int> d;
    
        int find(int node) {
            if (parent[node] == -1) return node;
            return parent[node] = find(parent[node]);
        }
    
        void Union(int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);
            if (root1 == root2) return;
            if (d[root1] > d[root2]) parent[root2] = root1;
            else if (d[root1] < d[root2]) parent[root1] = root2;
            else {
                parent[root2] = root1;
                d[root1]++;
            }
        }
    
    
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            parent.resize(n, -1);
            d.resize(n, 0);
    
            for (auto &e : edges) {
                Union(e[0], e[1]);
            }
    
            vector<int> edge_num(n, 0);
            for (auto &e : edges) {
                edge_num[find(e[0])]++;
            }
    
            vector<int> node_num(n, 0);
            for (int i = 0; i < n; i++) {
                node_num[find(i)]++;
            }
    
            int ans = 0;
            for (int i = 0; i < n; i++) {
                if (node_num[i] == 0) continue;
                else if (node_num[i] == 1) ans++;
                else if ((node_num[i] * (node_num[i]-1) / 2) == edge_num[i]) ans++;
            }
    
            return ans;
        }
    };
    
    
