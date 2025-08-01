class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int i = 2; i <= numRows; i++) {
            ans.push_back({});
            for (int j = 0; j < i; j++) {
                int left = (j - 1 >= 0) ? ans[i-2][j-1] : 0;
                int right = (j < i-1) ? ans[i-2][j] : 0;
                ans[i-1].push_back(left+right);
            }
        }
        return ans;
    }
};
