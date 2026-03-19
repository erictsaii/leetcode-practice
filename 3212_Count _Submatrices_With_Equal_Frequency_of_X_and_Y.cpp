class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> v(m, vector<int>(n, INT_MAX));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'X') v[i][j] = 1;
                else if (grid[i][j] == 'Y') v[i][j] = -1;
            }
            for (int j = 1; j < n; j++) {
                if (v[i][j] == INT_MAX) v[i][j] = v[i][j-1];
                else if (v[i][j-1] != INT_MAX) v[i][j] += v[i][j-1];
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i != 0) {
                    if (v[i][j] == INT_MAX) v[i][j] = v[i-1][j];
                    else if (v[i-1][j] != INT_MAX) v[i][j] += v[i-1][j];
                }

                if (v[i][j] == 0) ans++;
            }
        }

        return ans;
    }
};
