class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt = 0;
        int ans = 0;
        int start = 0;
        for (int end = 0; end < nums.size(); end++) {
            if (nums[end] == 0) cnt++;
            while (cnt > 1) {
                if (nums[start++] == 0) cnt--;
            }
            ans = max(ans, end-start);
        }

        return ans;
    }
};