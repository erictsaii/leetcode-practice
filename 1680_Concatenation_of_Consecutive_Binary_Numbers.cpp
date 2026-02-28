class Solution {
public:
    int binary_len(int n) {
        int len = 0;

        while (n) {
            len++;
            n >>= 1;
        }

        return len;
    }

    int concatenatedBinary(int n) {
        long long ans = 0;
        int MOD = 1e9 + 7;

        for (int i = 1; i <= n; i++) {
            ans <<= binary_len(i);
            ans += i;
            ans = ans % MOD;
        }

        return ans;
    }
};
