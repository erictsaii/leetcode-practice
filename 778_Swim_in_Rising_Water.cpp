class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        while (pq.size()) {
            auto [curr_max, y, x] = pq.top();
            pq.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i]; 

                if (nx == n-1 && ny == n-1) return max(curr_max, grid[ny][nx]);

                if (0<=nx && nx<n && 0<=ny && ny<n && !visited[ny][nx]) {
                    visited[ny][nx] = true;
                    pq.push({max(grid[ny][nx], curr_max), ny, nx});
                }
            }
        }

        return 0; // not reach
    }
};


// 從左上走到右下，找到一條path，path中的max element是最小的
// priority_queue<tuple<int, int, int>> pq; // curr_max, i, j
