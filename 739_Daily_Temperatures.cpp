class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stk; // idx

        vector<int> ans(n, 0);
        stk.push(n-1);
        for (int i = n-2; i >= 0; i--) {
            while (!stk.empty() && temperatures[stk.top()] <= temperatures[i]) stk.pop();
            if (!stk.empty()) ans[i] = stk.top() - i;
            stk.push(i);
        }

        return ans;
    }
};
