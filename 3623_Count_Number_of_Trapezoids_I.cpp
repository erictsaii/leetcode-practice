using ll = long long;
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, ll> cnt; // y coordinate -> frequency

        for (auto& point : points) {
            cnt[point[1]]++;
        }

        for (auto& c : cnt) {
            c.second = c.second * (c.second - 1) / 2;
        }

        ll sum = 0;
        for (auto& c : cnt) {
            sum += c.second;
        }

        int ans = 0;
        int MOD = 1e9+7;
        for (auto& c : cnt) {
            sum -= c.second;
            ans = (ans + (c.second * sum) % MOD) % MOD;
        }
        return ans;
    }
};

// y[0]: 2 -> 1
// y[5]: 3 -> 3
// y[10]: 3 -> 3


// 1*3 + 1*3 + 3*3

// 1*(3+3) + 3*3
