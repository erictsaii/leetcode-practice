class Solution {
public:
    int count_gap(long a, long b, int n) {
        int gap;

        while (a <= n) {
            gap += min(b, 1L * (n+1)) - a;
            a *= 10;
            b *= 10;
        }

        return gap;
    }

    int findKthNumber(int n, int k) {
        int ans = 1;
        k--;

        while (k != 0) {
            int gap = count_gap(ans, ans+1, n);
            if (k >= gap) {
                k -= gap;
                ans++;
            }
            else {
                k--;
                ans *= 10;
            }
        }


        return ans;
    }
};
