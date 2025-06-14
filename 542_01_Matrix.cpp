class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q; // y, x

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
        while (!q.empty()) {
            int y = q.front().first, x = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int n_y = y + dy[i], n_x = x + dx[i];
                if (0<=n_y && n_y<m && 0<=n_x && n_x<n && ans[n_y][n_x] == -1) {
                    ans[n_y][n_x] = ans[y][x] + 1;
                    q.push({n_y, n_x});
                }
            }
        }

        return ans;
    }
};

// bfs
// 距離0距離1的先更新，接下來距離2更新...
