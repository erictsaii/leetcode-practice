class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);

        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (auto& word : wordDict) {
                int len = word.size();
                if (i-len>=0 && dp[i-len] && s.substr(i-len, len) == word) {
                    dp[i] = true;
                }
            }
        }


        return dp[n];
    }
};
