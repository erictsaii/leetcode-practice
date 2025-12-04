class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size(); 
        vector<int> dp(m+1, 0), prev_dp(m+1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[j] = prev_dp[j-1] + 1;
                }
                else {
                    dp[j] = max(prev_dp[j], dp[j-1]);
                }
            }
            prev_dp = dp;
        }
        return n + m - 2*dp[m];
    }
};



// word1 = "a" word2 = "b"
// ans = word1.size() - LCS_len + word2.size() - LCS_len

// dp[i][j]: the longest common subsequence length of using the first i char in word1 
// and the first j char in word2

// init: dp[0][0~j] = 0, dp[0~i][0] = 0

// if word1[i-1] == word2[j-1]: dp[i][j] = dp[i-1][j-1] + 1
// else dp[i][j] = max(dp[i-1][j], dp[i][j-1])
