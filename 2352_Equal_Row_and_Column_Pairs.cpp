class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> rows;
        int n = grid.size();

        for (int i = 0; i < n; i++) {
            vector<int> tmp_row(n);
            for (int j = 0; j < n; j++) {
                tmp_row[j] = grid[i][j];
            }
            rows[tmp_row]++;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> tmp_col(n);
            for (int j = 0; j < n; j++) {
                tmp_col[j] = grid[j][i];
            }
            ans += rows[tmp_col];
        }
        
        return ans;
    }
};

// row: 3122 1445 2422 2422
// col: 3122 1444 2422 2522