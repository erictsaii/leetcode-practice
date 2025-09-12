class NumMatrix {
public:
    vector<vector<int>> sum;

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> row_sum(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                tmp += matrix[i][j];
                row_sum[i][j] = tmp;
            }
        } 

        sum.assign(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            int tmp = 0;
            for (int i = 0; i < m; i++) {
                tmp += row_sum[i][j];
                sum[i][j] = tmp;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = sum[row2][col2];

        if (row1 - 1 >= 0) ans -= sum[row1-1][col2];
        if (col1 - 1 >= 0) ans -= sum[row2][col1-1];
        if (row1 - 1 >= 0 && col1 - 1 >= 0) ans += sum[row1-1][col1-1];

        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
