class Solution {
public:
    int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> dp(n, vector<double>(n, 1.0));
        vector<vector<double>> tmp = dp;

        for (int round = 0; round < k; round++) {
            for (int y = 0; y < n; y++) {
                for (int x = 0; x < n; x++) {
                    double sum = 0.0;
                    for (int i = 0; i < 8; i++) {
                        int n_x = dx[i] + x;
                        int n_y = dy[i] + y;
                        if (0<=n_x && n_x<n && 0<=n_y && n_y<n) {
                            sum += dp[n_y][n_x];
                        }
                    }
                    tmp[y][x] = sum / 8.0;
                }
            }
            dp = tmp;
        }

        return dp[row][column];
    }
};
