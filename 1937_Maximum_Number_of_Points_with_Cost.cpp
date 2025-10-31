using ll = long long;
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<vector<ll>> dp(m, vector<ll>(n, 0));

        // init for the first row
        for (int i = 0; i < n; i++) {
            dp[0][i] = points[0][i];
        }

        for (int i = 1; i < m; i++) {
            vector<ll> to_left(n, 0);
            vector<ll> to_right(n, 0);

            to_right[0] = dp[i-1][0];
            for (int j = 1; j < n; j++) {
                to_right[j] = max(to_right[j-1]-1, dp[i-1][j]);
            }

            to_left[n-1] = dp[i-1][n-1];
            for (int j = n-2; j >= 0; j--) {
                to_left[j] = max(to_left[j+1]-1, dp[i-1][j]);
            }

            for (int j = 0; j < n; j++) {
                dp[i][j] = points[i][j] + max(to_left[j], to_right[j]);
            }
        }

        ll ans = -1;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[m-1][i]);
        }
        return ans;
    }
};
