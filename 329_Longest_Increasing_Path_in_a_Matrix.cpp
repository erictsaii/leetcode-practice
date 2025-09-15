class Solution {
public:
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    int m, n;

    int dfs(int y, int x, vector<vector<int>>& dp, vector<vector<int>>& matrix) {
        if (dp[y][x] != 1) return dp[y][x];
        int max_length = 0;
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (0<=nx && nx<n && 0<=ny && ny<m && matrix[ny][nx] > matrix[y][x]) {
                max_length = max(max_length, dfs(ny, nx, dp, matrix));
            }
        }
        dp[y][x] = max_length + 1;
        return dp[y][x];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 1));

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(i, j, dp, matrix));
            }
        }
        return ans;
    }
};
