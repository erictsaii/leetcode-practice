class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] && i > 0) {
                    matrix[i][j] += matrix[i-1][j];
                }
            }

            vector<int> curr = matrix[i];
            sort(curr.begin(), curr.end(), greater());
            for (int j = 0; j < n; j++) {
                ans = max(ans, (j+1) * curr[j]);
            }
        }

        return ans;
    }
};
