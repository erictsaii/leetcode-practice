class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    int find(vector<vector<int>>& events, int now_idx) {
        int l = 0, r = now_idx-1;
        int result = -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (events[mid][1] < events[now_idx][0]) {
                result = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return result;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), cmp);
        int n = events.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

        for (int i = 1; i <= n; i++) {
            int nearest_valid_idx = find(events, i-1);
            for (int j = 1; j <= k; j++) {
                dp[i][j] = max(dp[i-1][j], dp[nearest_valid_idx + 1][j-1] + events[i-1][2]);
            }
        }

        return dp[n][k];
    }

};
