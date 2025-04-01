class Solution {
    public:
        long long dfs(int pos, vector<long long>& dp, vector<vector<int>>& questions) {
            if (pos >= questions.size()) return 0;
            if (dp[pos] != -1) return dp[pos];
            long long take, skip;
            take = questions[pos][0] + dfs(pos+questions[pos][1]+1, dp, questions);
            skip = dfs(pos+1, dp, questions);
            dp[pos] = max(take, skip);
            return dp[pos];
        }
        long long mostPoints(vector<vector<int>>& questions) {
            vector<long long> dp(questions.size(), -1);
            return dfs(0, dp, questions);
        }
    };