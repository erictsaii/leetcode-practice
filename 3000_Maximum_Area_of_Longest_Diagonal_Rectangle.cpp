class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_diagonal = 0;
        int ans;

        for (auto& dim : dimensions) {
            int d = dim[0]*dim[0] + dim[1]*dim[1];
            if (d > max_diagonal) {
                ans = dim[0]*dim[1];
                max_diagonal = d;
            }
            else if (d == max_diagonal) {
                ans = max(ans, dim[0]*dim[1]);
            }
        }

        return ans;
    }
};
