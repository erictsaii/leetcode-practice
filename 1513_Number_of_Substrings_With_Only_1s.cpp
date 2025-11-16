using ll = long long;
class Solution {
public:
    int numSub(string s) {
        ll ans = 0;
        ll MOD = 1e9+7;
        ll cnt = 0;

        for (auto& c : s) {
            if (c == '0') {
                if (cnt) ans = (ans + cnt * (cnt+1) / 2) % MOD;
                cnt = 0;
            }
            else {
                cnt++;
            }
        }
        if (cnt) ans = (ans + cnt * (cnt+1) / 2) % MOD;
        return ans;
    }
};

// 1: 1
// 11: 3 (1+2)
// 111: 6 (1+2+3)
// 1111: 10 (1+2+3+4)
