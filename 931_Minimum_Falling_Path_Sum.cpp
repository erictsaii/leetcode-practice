class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);

        // init
        for (int i = 0; i < n; i++) {
            prev[i] = matrix[0][i];
        }

        // dp calculation
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int l = (j-1 >= 0) ? prev[j-1] : 10000;
                int r = (j+1 < n) ? prev[j+1] : 10000;
                curr[j] = matrix[i][j] + min({l, prev[j], r});
            }
            prev = curr;
        }

        // find the minimum
        int ans = 10000;
        for (int i = 0; i < n; i++) {
            ans = min(ans, prev[i]);
        }
        return ans;
    }
};

// dp approach
// dp[i][j] = matrix[i][j] + min(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1])
// time complexity: O(n^2)
// the space could be further optimized
