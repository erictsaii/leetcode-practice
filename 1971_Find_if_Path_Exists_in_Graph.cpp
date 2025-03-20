class Solution {
    public:
        vector<int> parent;
        vector<int> d;
    
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
    
        bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
            parent.resize(n, -1);
            d.resize(n, 0);
            for (auto &e : edges) {
                Union(e[0], e[1]);
            }
            return find(source) == find(destination);
        }
    };