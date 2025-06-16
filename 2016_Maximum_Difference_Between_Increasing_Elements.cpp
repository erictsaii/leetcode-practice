class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min_val = nums[0];
        int ans = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= min_val) {
                min_val = nums[i];
                continue;
            }
            ans = max(ans, nums[i]-min_val);
        }
        return ans;
    }
};
