class Solution {
    public:
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        vector<int> parent; // y * n + x 
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
    
        int largestIsland(vector<vector<int>>& grid) {
            int n = grid.size();
            parent.resize(n*n, -1);
            d.resize(n*n, 0);
    
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        // 4 dircetions
                        for (int k = 0; k < 4; k++) {
                            int x = dx[k] + j;
                            int y = dy[k] + i;
                            if (0<=x && x<n && 0<=y && y<n && grid[y][x]==1) Union(y*n+x, i*n+j);
                        }
                    }
                }
            }
    
            vector<int> island_size(n*n);
    
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j]) {
                        island_size[find(i*n+j)]++;
                    }
                }
            }
    
            int ans = -1;
    
            for (auto island : island_size) {
                ans = max(ans, island);
            }
    
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 0) {
                        int cnt = 1;
                        map<int, bool> m;
                        for (int k = 0; k < 4; k++) {
                            int x = dx[k] + j;
                            int y = dy[k] + i;
                            if (0<=x && x<n && 0<=y && y<n && grid[y][x]==1) {
                                m[find(y*n+x)] = true;
                            }
                        }
                        for (auto mi : m) cnt += island_size[mi.first];
                        ans = max(ans, cnt);
                    }
                }
            }
            return ans;
        }
    };
    
    // for every 1, Union with 4 direction's 1 
    
    // for every zeros, fake Union with 4 direction