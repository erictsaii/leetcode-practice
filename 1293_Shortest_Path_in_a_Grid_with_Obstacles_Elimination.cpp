class Solution {
public:
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

    bool valid(int y, int x, int m, int n) {
        return 0<=y && y<m && 0<=x && x<n;
    }

    int shortestPath(vector<vector<int>>& grid, int k) { 
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) return 0;
        vector<vector<int>> visited(m, vector<int>(n, 1e9));
        visited[0][0] = 0;

        queue<vector<int>> q; // y, x, dis, curr_k
        q.push({0, 0, 0, 0});
        while (q.size()) {
            auto now = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = now[0] + dy[i], nx = now[1] + dx[i];
                if (ny == m-1 && nx == n-1) return now[2]+1;

                if (!valid(ny, nx, m, n)) continue;

                int next_k = (grid[ny][nx] == 1) ? now[3]+1 : now[3];
                if (next_k > k) continue;
                if (visited[ny][nx] <= next_k) continue;

                visited[ny][nx] = next_k;
                q.push({ny, nx, now[2]+1, next_k});
            }
        }
        return -1;
    }
};

// 1 <= k <= 1600

