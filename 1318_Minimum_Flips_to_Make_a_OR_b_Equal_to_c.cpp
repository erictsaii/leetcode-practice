class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while (a!=0 || b!=0 || c!=0) {
            if (c & 1) {
                if (((a | b) & 1) == 0) ans++;
            }
            else {
                if ((a | b) & 1) {
                    ans += (a & 1) + (b & 1);
                }
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return ans;
    }
};

// if now 0, needs to be 1, plus 1 operation
// if now 1, needs to be 0, plus (if a is 1) + (if b is 1)
