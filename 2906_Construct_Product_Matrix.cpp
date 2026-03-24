using ll = long long;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int MOD = 12345, n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 1));
        ll product = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = product;
                product *= grid[i][j];
                product %= MOD;
            }
        }

        product = 1;
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                ans[i][j] *= product;
                ans[i][j] %= MOD;

                product *= grid[i][j];
                product %= MOD;
            }
        }
        
        return ans;
    }
};
