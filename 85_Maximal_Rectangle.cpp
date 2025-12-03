class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }

            stack<int> stk;
            for (int j = 0; j < n; j++) {
                while (stk.size() && heights[j] < heights[stk.top()]) {
                    int h = heights[stk.top()];
                    stk.pop();
                    int next_smaller_index = j;
                    int prev_smaller_index = stk.size() ? stk.top() : -1;
                    ans = max(ans, h * (next_smaller_index - prev_smaller_index - 1));
                }
                stk.push(j);
            }
            while (stk.size()) {
                int h = heights[stk.top()];
                stk.pop();
                int next_smaller_index = n;
                int prev_smaller_index = stk.size() ? stk.top() : -1;
                ans = max(ans, h * (next_smaller_index - prev_smaller_index - 1));
            }   
        }
        return ans;
    }
};
