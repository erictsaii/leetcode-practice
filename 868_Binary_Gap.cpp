class Solution {
public:
    int binaryGap(int n) {
        int prev_idx = -1, curr_idx = 0;
        int ans = 0;

        while (n) {
            if (n & 1) {
                if (prev_idx != -1) {
                    ans = max(ans, curr_idx - prev_idx);
                }
                prev_idx = curr_idx;
            }
            n >>= 1;
            curr_idx++;
        }

        return ans;
    }
};
