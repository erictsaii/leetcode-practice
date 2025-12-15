class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        int prefix;
        for (int i = 0; i < m; i++) {
            prefix = 0;
            for (int j = 0; j < n; j++) {
                prefix += mat[i][j];
                if (i - 1 >= 0) dp[i][j] += dp[i-1][j];
                dp[i][j] += prefix; 
            }
        }

        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int r1 = min(m-1, i+k), c1 = min(n-1, j+k);
                int r2 = max(0, i-k), c2 = max(0, j-k);

                ans[i][j] = dp[r1][c1];
                if (r2-1 >= 0) ans[i][j] -= dp[r2-1][c1];
                if (c2-1 >= 0) ans[i][j] -= dp[r1][c2-1];
                if (r2-1 >= 0 && c2-1 >= 0) ans[i][j] += dp[r2-1][c2-1];
            }
        }
        return ans;
    }
};
