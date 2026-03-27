class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        k %= n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i & 1) { // shift right
                    if (mat[i][(j + k) % n] != mat[i][j]) return false;
                }
                else {
                    if (mat[i][(j + n - k) % n] != mat[i][j]) return false;
                }
            }
        }

        return true;
    }
};


// 0 -> 2
// 1 -> 0
// 2 -> 1

// (i + n - k) % n
