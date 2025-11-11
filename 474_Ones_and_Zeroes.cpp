class Solution {
public:
    int memo[601][101][101] = {0};

    int dfs(vector<string>& strs, int idx, int zero_cnt, int one_cnt, int m, int n) {
        if (idx >= strs.size()) return 0;
        if (memo[idx][zero_cnt][one_cnt]) return memo[idx][zero_cnt][one_cnt];

        int zero = count(strs[idx].begin(), strs[idx].end(), '0');
        int one = strs[idx].size() - zero;

        int skip = dfs(strs, idx+1, zero_cnt, one_cnt, m, n);
        int take = 0;
        if (zero_cnt+zero <= m && one_cnt+one <= n) take = dfs(strs, idx+1, zero_cnt+zero, one_cnt+one, m, n) + 1;
        
        return memo[idx][zero_cnt][one_cnt]= max(skip, take);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        return dfs(strs, 0, 0, 0, m, n);
    }
};

// dp[i][j][k]: the max size of the state: from 0 to ith element in strs, curr_m, curr_n
