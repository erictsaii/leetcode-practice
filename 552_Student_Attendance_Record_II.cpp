using ll = long long;
class Solution {
public:
    int checkRecord(int n) {
        vector<vector<ll>> dp(3, vector<ll>(2, 0));
        vector<vector<ll>> new_dp(3, vector<ll>(2, 0));

        dp[0][0] = 1;
        dp[1][0] = 1;
        dp[2][0] = 0;

        dp[0][1] = 1;
        dp[1][1] = 0;
        dp[2][1] = 0;

        ll MOD = 1e9+7;
        for (int i = 1; i < n; i++) {
            new_dp[0][0] = (dp[0][0] + dp[1][0] + dp[2][0]) % MOD;
            new_dp[1][0] = dp[0][0];
            new_dp[2][0] = dp[1][0];

            new_dp[0][1] = (dp[0][1] + dp[1][1] + dp[2][1] + dp[0][0] + dp[1][0] + dp[2][0]) % MOD;
            new_dp[1][1] = dp[0][1];
            new_dp[2][1] = dp[1][1];

            dp = new_dp;
        }

        ll ans = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                ans += dp[i][j];
                ans %= MOD;
            }
        }
        return ans;
    }
};

// total number of 'A' == 0 or 1
// no consecutive 3 'L'

// dp[n][3][2]

// dp[i][0][0] = dp[i-1][0][0] + dp[i-1][1][0] + dp[i-1][2][0]
// dp[i][1][0] = dp[i-1][0][0] 
// dp[i][2][0] = dp[i-1][1][0]

// dp[i][0][1] = dp[i-1][0][1] + dp[i-1][1][1] + dp[i-1][2][1] + dp[i-1][0][0] + dp[i-1][1][0] + dp[i-1][2][0]
// dp[i][1][1] = dp[i-1][0][1]
// dp[i][2][1] = dp[i-1][1][1]
