class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int prev = prices[0];
        int cnt = 1;
        long long ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] == prev - 1) {
                cnt++;
                prev--;
            }
            else {
                ans += 1LL * cnt * (cnt + 1) / 2;
                cnt = 1;
                prev = prices[i];
            }
        }
        ans += 1LL * cnt * (cnt + 1) / 2;
        return ans;
    }
};

// 3 2 1
// 3 * (3+1) / 2

// let's say the length of period is n
// the number of period would be n*(n+1) / 2
