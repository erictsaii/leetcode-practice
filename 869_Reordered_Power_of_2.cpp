class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<vector<int>> power(31, vector<int>(10, 0));
        int now = 1;

        for (int i = 0; i < 31; i++) {
            int tmp = now;
            while (tmp != 0) {
                power[i][tmp%10]++;
                tmp /= 10;
            }
            now <<= 1;
        }

        vector<int> n_digit(10, 0);
        while (n != 0) {
            n_digit[n%10]++;
            n /= 10;
        }

        for (int i = 0; i < 31; i++) {
            if (n_digit == power[i]) return true;
        }

        return false;
    }
};
