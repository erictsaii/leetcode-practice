class Solution {
public:
    bool is_same_k(long long n, int k) {
        string s = "";
        while (n > 0) {
            int bit = n % k;
            s.push_back('0' + bit);
            n /= k;
        }
        int l = 0, r = s.size()-1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    long long mirror_num(long long num, bool is_odd) {
        long long result = num;

        if (is_odd) num /= 10;
        while(num > 0) {
            result = result * 10 + num % 10;
            num /= 10;
        }
        return result;
    }

    long long kMirror(int k, int n) {
        long long ans = 0;
        
        for (long long i = 1; n > 0; i *= 10) {
            for (long long j = i; n > 0 && j < i * 10; j++) {
                long long p = mirror_num(j, true);
                if (is_same_k(p, k)) {
                    ans += p;
                    n--;
                }
            }
            for (long long j = i; n > 0 && j < i * 10; j++) {
                long long p = mirror_num(j, false);
                if (is_same_k(p, k)) {
                    ans += p;
                    n--;
                }
            }
        }

        return ans;
    }
};
