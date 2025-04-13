class Solution {
    public:
        int mod = 1e9 + 7;
        long long fastPow(long long a, long long n) {
            long long result = 1;
            while (n > 0) {
                if (n & 1) {
                    result = result * a % mod;
                }
                a = a * a % mod;
                n >>= 1;
            }
            return result;
        }
        int countGoodNumbers(long long n) {
            long long even_cnt = (n+1) / 2;
            long long prime_cnt = n / 2;
            int ans = fastPow(5, even_cnt) * fastPow(4, prime_cnt) % mod;
    
            return ans;
        }
    };