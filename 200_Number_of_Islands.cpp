class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        int dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    ans++;
                    q.push({i, j});
                    while (!q.empty()) {
                        int y = q.front().first, x = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int ny = dy[k] + y;
                            int nx = dx[k] + x;
                            if (0<=ny && ny<m && 0<=nx && nx<n && grid[ny][nx]=='1') {
                                grid[ny][nx] = '0';
                                q.push({ny, nx});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
