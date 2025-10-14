class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] < nums[i]) cnt++;
            else cnt = 1;
            if (cnt >= 2*k) return true;
        }

        int prev = -1;
        cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] < nums[i]) cnt++;
            else {
                prev = cnt;
                cnt = 1;
            }
            if (prev >= k && cnt >= k) return true;
        }
        return false;
    }
};
