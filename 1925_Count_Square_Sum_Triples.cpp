class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                int a_square = i*i - j*j;
                int a = sqrt(a_square);
                if (a*a == a_square) ans++;
            }
        }
        return ans;
    }
};


// a, b, c

// a^2 = c^2 - b^2

// iterate b c, find if exist a
// O(n^2)
