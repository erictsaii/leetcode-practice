class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long total = 0;
        int n = prices.size();
        
        for (int i = 0; i < n; i++) {
            total += prices[i]*strategy[i];
        }

        long long ans = total;
        for (int i = 0; i < k; i++) {
            total -= prices[i]*strategy[i];
        }
        for (int i = k/2; i < k; i++) {
            total += prices[i];
        }
        ans = max(ans, total);

        for (int i = 1; i + k -1 < n; i++) {
            total += 1LL*prices[i-1]*strategy[i-1];
            total -= prices[i+k/2-1];
            total -= 1LL * prices[i+k-1] * strategy[i+k-1];
            total += prices[i+k-1];
            ans = max(ans, total);
        }
        return ans;
    }
};
