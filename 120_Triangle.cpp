class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size());

        // initialize
        for (int i = 0; i < triangle.size(); i++) {
            dp[i].assign(triangle[i].size(), 0);
        }
        dp[0][0] = triangle[0][0];

        int one, two;
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                one = (j < dp[i-1].size()) ? dp[i-1][j] : INT_MAX;
                two = (0<=j-1 && j-1<dp[i-1].size()) ? dp[i-1][j-1] : INT_MAX;
                dp[i][j] = min(one, two) + triangle[i][j];
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < dp.back().size(); i++) {
            ans = min(ans, dp.back()[i]);
        }

        return ans;
    }
};
