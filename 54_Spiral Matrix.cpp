class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int total = m * n;

        vector<int> ans;
        int border = 0;
        while (total) {
            // right
            for (int i = border; i<n-border && total; i++, total--) {
                ans.push_back(matrix[border][i]);
            }

            // down
            for (int i = border + 1; i<m-border && total; i++, total--) {
                ans.push_back(matrix[i][n-1-border]);
            }

            // left
            for (int i = n-2-border; i>=border && total; i--, total--) {
                ans.push_back(matrix[m-1-border][i]);
            }

            // up
            for (int i = m-2-border; i>=border+1 && total; i--, total--) {
                ans.push_back(matrix[i][border]);
            }

            border++;
        }

        return ans;
    }
};
