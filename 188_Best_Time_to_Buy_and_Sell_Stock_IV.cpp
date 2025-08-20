class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> hold(n, vector<int>(k, 0));
        vector<vector<int>> not_hold(n, vector<int>(k, 0)); 

        for (int i = 0; i < k; i++) {
            hold[0][i] = -prices[0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k; j++) {
                if (j == 0) {
                    hold[i][j] = max(hold[i-1][j], -prices[i]);
                }
                else {
                    hold[i][j] = max(hold[i-1][j], not_hold[i-1][j-1]-prices[i]);
                }

                not_hold[i][j] = max(not_hold[i-1][j], hold[i-1][j]+prices[i]);
            }
        }

        return not_hold[n-1][k-1];
    }
};
