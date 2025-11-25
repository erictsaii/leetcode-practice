class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int rem = 0;
        for (int i = 1; i <= k; i++) {
            rem = (rem * 10 + 1) % k;
            if (rem == 0) return i;
        }
        return -1;
    }
};


// return the length of n
// n is divisible by k and only contains '1', e.g. 1, 11, 111...

// k = 2
// 1: 1
// 11: 1
// 111: 1

// k = 3
// 1: 1
// 11: 2
// 111: 0
// 1111 1
// 11111: 2

// k = 4
// 1: 1
// 11: 3
// 111: 3
// 1111: 3
// 每次都是再加 1eX
// no

// k = 5
// no

// k = 6
// 1: 1
// 11: 5
// 111: 3
// 1111: 1
// 11111: 5

// 如果出現同樣餘數時，直接return -1 (最多k次iteration)
// 解決overflow問題 -> mod
