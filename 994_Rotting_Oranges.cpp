class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;

        // count the number of fresh oranges and record where the rotten oranges at
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
        int time = 0;
        while (!q.empty() && fresh!=0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int y = q.front().first, x = q.front().second;
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int n_y = y + dy[j];
                    int n_x = x + dx[j];
                    if (0<=n_y && n_y<m && 0<=n_x && n_x<n && grid[n_y][n_x]==1) {
                        fresh--;
                        grid[n_y][n_x] = 2;
                        q.push({n_y, n_x});
                    }
                }
            }
            time++;
        }

        return (fresh == 0) ? time : -1;
    }
};

// may be impossible
