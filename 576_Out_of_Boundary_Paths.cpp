class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove == 0) return 0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove+1, 0)));

        for (int i = 0; i < m; i++) {
            dp[i][0][1]++;
            dp[i][n-1][1]++;
        }

        for (int j = 0; j < n; j++) {
            dp[0][j][1]++;
            dp[m-1][j][1]++;
        }

        int dy[4] = {0, 0, 1, -1};
        int dx[4] = {1, -1, 0, 0};
        int MOD = 1e9 + 7;
        for (int k = 2; k <= maxMove; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    for (int p = 0; p < 4; p++) {
                        int ny = i + dy[p];
                        int nx = j + dx[p];
                        if (0<=ny && ny<m && 0<=nx && nx<n) {
                            dp[i][j][k] += dp[ny][nx][k-1];
                            dp[i][j][k] %= MOD;
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int k = 1; k <= maxMove; k++) {
            ans += dp[startRow][startColumn][k];
            ans %= MOD;
        }
        return ans;
    }
};
