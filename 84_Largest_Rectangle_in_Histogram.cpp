class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int ans = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int h = heights[stk.top()];
                stk.pop();
                int next_smaller_element_idx = i;
                int prev_smaller_element_idx = stk.empty() ? -1 : stk.top();

                ans = max(ans, h * (next_smaller_element_idx - prev_smaller_element_idx - 1));
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            int h = heights[stk.top()];
            stk.pop();
            int next_smaller_element_idx = heights.size();
            int prev_smaller_element_idx = stk.empty() ? -1 : stk.top();

            ans = max(ans, h * (next_smaller_element_idx - prev_smaller_element_idx - 1));
        }

        return ans;
    }
};

