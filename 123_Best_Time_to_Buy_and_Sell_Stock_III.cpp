class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> buy1(n, 0);
        vector<int> buy2(n, 0);
        vector<int> sell1(n, 0);
        vector<int> sell2(n, 0);

        buy1[0] = -prices[0];
        buy2[0] = -prices[0];

        for (int i = 1; i < n; i++) {
            buy1[i] = max(buy1[i-1], -prices[i]);
            buy2[i] = max(buy2[i-1], sell1[i-1] - prices[i]);
            sell1[i] = max(sell1[i-1], buy1[i-1] + prices[i]);
            sell2[i] = max(sell2[i-1], buy2[i-1] + prices[i]);
        }

        return max(sell1[n-1], sell2[n-1]);
    }
};
