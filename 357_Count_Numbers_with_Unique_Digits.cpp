class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;

        int ans = 10;
        
        for (int i = 2; i <= n; i++) {
            int cnt = 9;
            for (int j = 0; j < i-1; j++) {
                cnt *= (9-j);
            }
            ans += cnt;
        }

        return ans; 
    }
};

// 10^8

// 0 1 2 3 4 5 6 7 8 9
// 1: 10
// 2: 81=9*9
// 3: 9*9*8
