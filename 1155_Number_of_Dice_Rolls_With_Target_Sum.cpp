class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<int> dp(target+1, 0);
        vector<int> new_dp(target+1, 0);

        dp[0] = 1;
        int MOD = 1e9+7;
        for (int dice = 1; dice <= n; dice++) {
            for (int t = 1; t <= target; t++) {
                int result = 0;
                for (int x = 1; x <= k; x++) {
                    if (t - x < 0) continue;
                    result += dp[t - x];
                    result %= MOD;
                }
                new_dp[t] = result;
            }
            dp = new_dp;
        }
        return dp[target];
    }
};

// a+b+c=target
// 0 <= a b c <= k

// dp[i][target]: using only i dices, the possible ways to sum up to be target

// answer: dp[n][target]
// dp[i][target] = dp[i-1][target-1] + dp[i-1][target-2] + ...dp[i-1][target-k]

// dp[0][0] = 1
