class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int digits = 0;
        int tmp = x;
        while (tmp) {
            digits++;
            tmp/=10;
        }

        int p = pow(10, digits-1);

        while (x) {
            int l = x/p;
            int r = x%10;
            if (l != r) return false;
            x %= p;
            x /= 10;
            p /= 100;
        }

        return true;
    }
};
