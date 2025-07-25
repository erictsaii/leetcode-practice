class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));

        // initialize
        for (int i = 0; i < n; i++) {
            dp[0][i] = grid[0][i];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int min_val = INT_MAX;
                for (int k = 0; k < n; k++) {
                    min_val = min(min_val, dp[i-1][k] + moveCost[grid[i-1][k]][j]);
                }
                dp[i][j] = min_val + grid[i][j];
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[m-1][i]);
        }

        return ans;
    }
};
