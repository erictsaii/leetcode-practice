class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    q.push({i, j});
                }
            }
        }

        if (q.size() == n*n || q.size() == 0) return -1;

        int ans = -1;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while (q.size()) {
            ans++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [y, x] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int ny = dy[k] + y, nx = dx[k] + x;
                    if (0<=ny && ny<n && 0<=nx && nx<n && grid[ny][nx] == 0) {
                        grid[ny][nx] = 1;
                        q.push({ny, nx});
                    }
                }
            }

        }
        return ans;
    }
};


// if the grid is all 0 or all 1, return -1

// BFS
