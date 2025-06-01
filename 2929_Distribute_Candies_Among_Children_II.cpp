class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;

        for (int i = 0; i <= min(n, limit); i++) {
            int remain = n - i;
            if (remain > 2 * limit) continue;
            int upper = min(remain, limit);
            int lower = remain - min(remain, limit); 
            ans += upper - lower + 1;
        }

        return ans;
    }
};

// distribute n candies to 3 children
// but each child get at most "limit" candies

// x + y + z = n
// x, y, z  <= limit
