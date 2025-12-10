class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    void dfs(vector<vector<int>>& grid, int y, int x) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if (0<=nx && nx<n && 0<=ny && ny<m && grid[ny][nx] == 0) {
                grid[ny][nx] = 1;
                dfs(grid, ny, nx);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        // delete the island one the border line
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) dfs(grid, i, 0);
            if (grid[i][n-1] == 0) dfs(grid, i, n-1);
        }
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 0) dfs(grid, 0, i);
            if (grid[m-1][i] == 0) dfs(grid, m-1, i);
        }

        int ans = 0;
        for (int i = 1; i < m-1; i++) {
            for (int j = 1; j < n-1; j++) {
                if (grid[i][j] == 0) {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};


// the island on the border line does not count
