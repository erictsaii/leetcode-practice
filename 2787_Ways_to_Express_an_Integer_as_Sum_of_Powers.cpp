class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<long long> nums;
        for (int i = 1; i <= n; i++) {
            int p = pow(i, x);
            if (p > n) break;
            nums.push_back(p);
        }

        unordered_map<long long, long long> prev, curr;
        int MOD = 1e9 + 7;

        for (auto& num : nums) {
            curr[num]++;
            for (auto& p : prev) {
                if (num + p.first <= n) {
                    curr[num + p.first] += p.second;
                    curr[num + p.first] %= MOD;
                }
            }
            prev = curr;
        }

        return curr[n];
    }
};

// 1: 1
// 2: 2
// 3: 3 1,2
// 4: 4 1,3
// 5: 5 1,4 2,3
// 6: 6 1,5 2,4
