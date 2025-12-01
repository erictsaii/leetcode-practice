class Solution {
public:
    int numSquares(int n) {
        vector<int> candidate;
        for (int i = 1; i * i <= n; i++) {
            candidate.push_back(i * i);
        }

        vector<int> dp(n+1, n);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < candidate.size(); j++) {
                if (i-candidate[j] >= 0) {
                    dp[i] = min(dp[i], dp[i-candidate[j]]+1);
                }
            }
        }
        return dp[n];
    }
};

// perfect square numbers: 1 4 9 16 25 ...
// greedy doesn't work

// 1: 1
// 2: 1 1
// 3: 1 1 1
// 4: 4
// 5: 1 4

// for each candidate x: 1 4 9 16 ...
// dp[i] = min(dp[i], dp[i-x]+1)


// n = 8
// 1 4
// 1: 1
// 2: 2
// 3: 3
// 4: 1

// O(n^3/2)
