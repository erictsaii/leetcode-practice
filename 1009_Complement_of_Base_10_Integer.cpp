class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;

        string s;

        while (n) {
            s.push_back('0' + !(n&1));
            n >>= 1;
        }

        int ans = 0;

        for (int i = s.size()-1; i >= 0; i--) {
            ans <<= 1;
            ans += s[i] - '0';
        }

        return ans;
    }
};
