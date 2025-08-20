class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> hold(n, 0); // max profit
        vector<vector<int>> not_hold(n, vector<int>(2, 0)); // 0 for not just sell, 1 for just sell

        hold[0] = -prices[0];

        for (int i = 1; i < n; i++) {
            hold[i] = max(hold[i-1], not_hold[i-1][0] - prices[i]);
            not_hold[i][0] = max(not_hold[i-1][0], not_hold[i-1][1]);
            not_hold[i][1] = hold[i-1] + prices[i];
        }

        return max(not_hold[n-1][0], not_hold[n-1][1]);
    }
};
