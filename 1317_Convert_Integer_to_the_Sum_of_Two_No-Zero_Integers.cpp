class Solution {
public:
    int zero_count(int num) {
        int cnt = 0;

        while (num) {
            if (num % 10 == 0) cnt++;
            num /= 10;
        }

        return cnt;
    }

    vector<int> getNoZeroIntegers(int n) {
        int b;
        for (int a = 1; a < n; a++) {
            b = n - a;
            if (zero_count(a) == 0 && zero_count(b) == 0) return {a, b};
        }
        return {0, n}; // not reach
    }
};
