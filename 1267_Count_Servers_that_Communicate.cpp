class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) { // there's a server
                    row[i]++;
                    col[j]++;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) { // there's a server
                    if ((row[i] >= 2) || (col[j] >= 2)) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};