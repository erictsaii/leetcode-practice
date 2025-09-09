class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long MOD = 1e9+7;
        vector<int> dp(n+1);
        dp[1] = 1;

        long can_share = 0;
        for (int i = 2; i <= n; i++) {
            if (i - delay >= 1) {
                can_share = (can_share + dp[i - delay]) % MOD;
            }
            if (i - forget >= 1) {
                can_share = (can_share - dp[i - forget] + MOD) % MOD;
            }
            dp[i] = can_share;
        }

        int ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};

// 用dp記 在第i天剛知道secret的人數

