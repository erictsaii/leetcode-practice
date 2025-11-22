class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    bool valid_pos(int y, int x, int n) {
        return 0<=y && y<n && 0<=x && x<n;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q; // y, x

        // turn one island to "2"
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 2;
                    found = true;
                }
            }
        }
        while (q.size()) {
            auto [y, x] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (valid_pos(ny, nx, n) && grid[ny][nx] == 1) {
                    grid[ny][nx] = 2;
                    q.push({ny, nx});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i, j});
            }
        }

        int ans = 0;
        while (q.size()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                auto [y, x] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (valid_pos(ny, nx, n)) {
                        if (grid[ny][nx] == 1) return ans;
                        else if (grid[ny][nx] == 0) {
                            grid[ny][nx] = 2;
                            q.push({ny, nx});
                        }
                    }
                }     
            }
            ans++;
        }
        return -1; // not reach
    }
};


// BFS
