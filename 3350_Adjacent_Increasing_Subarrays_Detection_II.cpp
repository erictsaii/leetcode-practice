class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int ans = 1;
        int cnt = 1;

        // cond 1
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] < nums[i]) cnt++;
            else cnt = 1;

            ans = max(ans, cnt/2);
        }

        int prev_cnt = 1;
        cnt = 1;
        // cond 2
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] < nums[i]) cnt++;
            else {
                prev_cnt = cnt;
                cnt = 1;
            }

            ans = max(ans, min(prev_cnt, cnt));
        }

        return ans;
    }
};

// cond 1: we have one increasing array -> ans = len/2
// cond 2: we have two increasing arrays -> ans = min(len1, len2)
