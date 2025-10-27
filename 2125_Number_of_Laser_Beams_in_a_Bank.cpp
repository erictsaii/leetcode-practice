class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size(), n = bank[0].size();
        int ans = 0;
        int prev, cnt = 0;

        for (int i = 0; i < n; i++) {
            if (bank[0][i] == '1') cnt++;
        }
        prev = cnt;
    
        for (int i = 1; i < m; i++) {
            cnt = 0;
            for (int j = 0; j < n; j++) {
                if (bank[i][j] == '1') cnt++;
            }
            if (cnt != 0) {
                ans += prev * cnt;
                prev = cnt;
            }
        }
        return ans;
    }
};
