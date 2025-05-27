class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;

        int dy[4] = {0, 0, -1, 1}, dx[4] = {1, -1, 0, 0};
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                if ((y==0 || y==m-1 || x==0 || x==n-1) && (y!=entrance[0] || x!=entrance[1])) {
                    return step;
                }
                for (int i = 0; i < 4; i++) {
                    int n_x = x + dx[i];
                    int n_y = y + dy[i];
                    if (0<=n_y && n_y<m && 0<=n_x && n_x<n && maze[n_y][n_x]!='+' && !visited[n_y][n_x]) {
                        visited[n_y][n_x] = true;
                        q.push({n_y, n_x});
                    }
                }
            }
            step++;
        }

        return -1;
    }
};