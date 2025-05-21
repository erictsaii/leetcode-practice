class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int col = 0, row = 0; // record if the first row and col should be zero

        // record the which row/col should be zero
        for (int i = 0; i < m; i++) if (matrix[i][0]==0) col = 1;
        for (int i = 0; i < n; i++) if (matrix[0][i]==0) row = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // traverse every element to see whether they should be zero
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[0][j]==0 || matrix[i][0]==0) matrix[i][j] = 0;
            }
        }

        // handle the first col/row
        if (col) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (row) {
            for (int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }
  
    }
};
