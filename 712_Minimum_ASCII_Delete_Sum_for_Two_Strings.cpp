class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + s1[i-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }         
            }
        }

        int sum = 0;
        for (auto& c : s1) sum += c;
        for (auto& c : s2) sum += c;
        return sum - 2*dp[n][m];
    }
};


// TODO:
// find the max ASCII sum (like LCS)
// calculate the ASCII sum of s1, s2
// return s1_sum + s2_sum - 2*LCS_sum
