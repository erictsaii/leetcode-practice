class Solution {
    public:
        bool has_even_digit(int num) {
            int cnt = 0;
            while (num != 0) {
                num /= 10;
                cnt++;
            }
            return cnt % 2 == 0;
        }
        int findNumbers(vector<int>& nums) {
            int ans = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (has_even_digit(nums[i])) ans++;
            }
            return ans;
        }
    };