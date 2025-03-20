class Solution {
    public:
        vector<int> parent;
        vector<int> depth;
    
        int find(int node) {
            if (parent[node] == -1) return node;
            return parent[node] = find(parent[node]);
        }
    
        void Union(int node_1, int node_2) {
            int root_1 = find(node_1);
            int root_2 = find(node_2);
            if (root_1 == root_2) return;
            if (depth[root_1] > depth[root_2]) parent[root_2] = root_1;
            else if (depth[root_1] < depth[root_2]) parent[root_1] = root_2;
            else {
                parent[root_2] = root_1;
                depth[root_1]++;
            }
        }
    
        vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
            parent.resize(n, -1);
            depth.resize(n, 0);
    
            vector<unsigned int> cost(n, -1);
            for (auto &e : edges) {
                Union(e[0], e[1]);
            }
            for (auto &e : edges) {
                int root = find(e[0]);
                cost[root] &= e[2];
            }
    
            vector<int> ans;
            for (auto &q : query) {
                if (find(q[0]) != find(q[1])) ans.push_back(-1);
                else {
                    int root = find(q[0]);
                    ans.push_back(cost[root]);
                }
            }
            return ans;
        }
    
    
    };
    
    