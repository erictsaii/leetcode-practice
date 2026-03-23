using ll = long long;
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<pair<ll, ll>>> dp(m, vector<pair<ll, ll>>(n, {-1, 1})); // max_pos, min_neg

        ll product = 1;
        for (int i = 0; i < n; i++) {
            product *= grid[0][i];
            dp[0][i].first = product;
            dp[0][i].second = product;
        }

        product = 1;
        for (int i = 0; i < m; i++) {
            product *= grid[i][0];
            dp[i][0].first = product;
            dp[i][0].second = product;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] >= 0) {
                    dp[i][j].first = max(grid[i][j]*dp[i-1][j].first, grid[i][j]*dp[i][j-1].first);
                    dp[i][j].second = min(grid[i][j]*dp[i-1][j].second, grid[i][j]*dp[i][j-1].second);
                }
                else {
                    dp[i][j].first = max(grid[i][j]*dp[i-1][j].second, grid[i][j]*dp[i][j-1].second);
                    dp[i][j].second = min(grid[i][j]*dp[i-1][j].first, grid[i][j]*dp[i][j-1].first);
                }
            }
        }

        int MOD = 1e9+7;

        return (dp[m-1][n-1].first >= 0) ? dp[m-1][n-1].first % MOD : -1;
    }
};
