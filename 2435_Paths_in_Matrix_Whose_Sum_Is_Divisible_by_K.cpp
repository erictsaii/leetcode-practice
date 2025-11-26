class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> cnt(m, vector<vector<int>>(n, vector<int>(k, 0)));

        // init
        int remain = 0;
        for (int i = 0; i < n; i++) {
            remain = (remain + grid[0][i]) % k;
            cnt[0][i][remain]++;
        }

        remain = grid[0][0];
        for (int i = 1; i < m; i++) {
            remain = (remain + grid[i][0]) % k;
            cnt[i][0][remain]++;
        }

        int MOD = 1e9+7;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                for (int x = 0; x < k; x++) {
                    // up
                    remain = (x + grid[i][j]) % k;
                    cnt[i][j][remain] += cnt[i-1][j][x];
                    
                    // left
                    cnt[i][j][remain] += cnt[i][j-1][x];
                    cnt[i][j][remain] %= MOD;
                }
            }
        }

        return cnt[m-1][n-1][0];
    }
};


// k很小
// 開一個3D array，m*n*k
