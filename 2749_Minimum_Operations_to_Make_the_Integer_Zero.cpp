class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; k++) {
            long long x = num1 - 1LL*k*num2;
            if (x < k) return -1;
            if (__builtin_popcountll(x) <= k) return k;
        }
        return -1;
    }
};


// assume after k operations
// we got num1 = x + k*num2
// if the bit 1 in x <= k, we can return k
