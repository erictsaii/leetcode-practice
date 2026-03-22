class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (mat == target) return true;

        int times = 3;
        int n = mat.size();

        while (times--) {
            vector<vector<int>> new_mat(n, vector<int>(n, 0));

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    new_mat[j][n - i - 1] = mat[i][j];
                }
            }

            mat = new_mat;

            if (mat == target) return true;
        }

        return false;
    }
};
