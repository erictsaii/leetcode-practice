using ll = long long;
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<ll>> buy(n, vector<ll>(k, 0));
        vector<vector<ll>> spare(n, vector<ll>(k, 0));
        vector<vector<ll>> sell(n, vector<ll>(k, 0));

        for (int i = 0; i < k; i++) {
            buy[0][i] = -prices[0];
            sell[0][i] = prices[0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k; j++) {
                if (j == 0) {
                    buy[i][j] = max(buy[i-1][j], (ll)-prices[i]);
                    sell[i][j] = max(sell[i-1][j], (ll)prices[i]);
                }
                else {
                    buy[i][j] = max(buy[i-1][j], spare[i-1][j-1]-prices[i]);
                    sell[i][j] = max(sell[i-1][j], spare[i-1][j-1]+prices[i]);
                }

                spare[i][j] = max({spare[i-1][j], buy[i-1][j]+prices[i], sell[i-1][j]-prices[i]});
            }
        }

        return spare[n-1][k-1];
    }
};
