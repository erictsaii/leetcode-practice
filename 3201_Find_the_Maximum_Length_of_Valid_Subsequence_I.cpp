class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even_cnt = 0;
        int odd_cnt = 0;

        int ans;
        for (auto& n : nums) {
            if (n & 1) odd_cnt++;
            else even_cnt++;
        }
        ans = max(even_cnt, odd_cnt);

        odd_cnt = even_cnt = 0;
        int to_find = 1;
        
        for (auto& n : nums) {
            if ((n & 1) == to_find) {
                odd_cnt++;
                to_find = (to_find) ? 0 : 1;
            }
        }
        to_find = 0;
        for (auto& n : nums) {
            if ((n & 1) == to_find) {
                even_cnt++;
                to_find = (to_find) ? 0 : 1;
            }
        }

        ans = max({ans, odd_cnt, even_cnt});

        return ans;
    }
};
