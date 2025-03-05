class Solution {
    public:
        long long coloredCells(int n) {
            long long _n = n;
            long long ans = _n + 2 * _n * (_n-1) / 2;
            ans *= 2;
            ans -= 1 + 2* (n-1);
    
            return ans;
        }
    };
    
    