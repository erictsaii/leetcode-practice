class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0) return 1.0;

        // init
        vector<double> dp(k+maxPts+1, 0);
        for (int i = k; i < dp.size(); i++) {
            if (i <= n) dp[i] = 1;
        }

        for (int i = 1; i <= maxPts; i++) {
            dp[k-1] += dp[k-1+i];
        }
        dp[k-1] /= maxPts;

        for (int i = k-2; i >= 0; i--) {
            dp[i] = dp[i+1] - dp[i+1+maxPts]/maxPts + dp[i+1]/maxPts; 
        }

        return dp[0];
    }
};
