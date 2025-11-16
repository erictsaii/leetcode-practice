class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> dp(n, {1, 1}); // length, number of ways to get this length

        int max_length = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (nums[i] < nums[j]) {
                    if (dp[j].first < dp[i].first+1) {
                        dp[j].first = dp[i].first+1;
                        dp[j].second = dp[i].second;
                    }
                    else if (dp[j].first == dp[i].first+1) {
                        dp[j].second += dp[i].second;
                    }
                }
            }
            max_length = max(max_length, dp[i].first);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i].first == max_length) ans += dp[i].second;
        }
        return ans;
    }
};
