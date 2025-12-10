class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        int cnt;

        for (auto& account : accounts) {
            cnt = 0;
            for (auto& money : account) {
                cnt += money;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
