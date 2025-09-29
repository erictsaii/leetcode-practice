class Solution {
public:
    vector<vector<int>> memo;

    int solve(int l, int r, vector<int>& val) {
        if (r-l == 1) return 0;
        if (memo[l][r] != -1) return memo[l][r];

        int result = INT_MAX;
        for (int k = l + 1; k < r; k++) {
            result = min(result, solve(l, k, val) + solve(k, r, val) + val[l]*val[k]*val[r]);
        }
        
        return memo[l][r] = result;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        memo.assign(n, vector<int>(n, -1));
        return solve(0, n-1, values);
    }
};

// find minimum possible score after some triangulation
// top-down dp
// return dp(l = 0, r = n-1)
// for k from l+1 to r-1:
//   result = min(result, dp(l, k) + dp(k, r) + val[l]*val[k]*val[r])
// dp[l][r] = result
