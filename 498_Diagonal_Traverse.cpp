class Solution {
public:
    vector<int> ans;
    int m, n;

    void solve(int y, int x, vector<vector<int>>& mat, int y_dir, int x_dir) {
        ans.push_back(mat[y][x]);

        if (y == m-1 && x == n-1) {
            return;
        }
        else if (y == 0 && y_dir == -1) {
            if (x != n-1) solve(y, x+1, mat, 1, -1);
            else solve(y+1, x, mat, 1, -1);
        }
        else if (x == 0 && x_dir == -1) {
            if (y != m-1) solve(y+1, x, mat, -1, 1);
            else solve(y, x+1, mat, -1, 1);
        }
        else if (y == m-1 && y_dir == 1) {
            solve(y, x+1, mat, -1, 1);
        }
        else if (x == n-1 && x_dir == 1) {
            solve(y+1, x, mat, 1, -1);
        }
        else {
            solve(y+y_dir, x+x_dir, mat, y_dir, x_dir);
        }
    }

    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        solve(0, 0, mat, -1, 1);
        return ans;
    }
};
