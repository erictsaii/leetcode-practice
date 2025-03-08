class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int ans = INT_MAX, tmp = 0;
            for (int right = 0; right < blocks.size(); right++) {
                if (blocks[right] == 'W') tmp++;
                if (right - k + 1 >= 0) {
                    ans = min(ans, tmp);
                    if (blocks[right - k + 1] == 'W') tmp--;
                }
            }
            return ans;
        }
    };