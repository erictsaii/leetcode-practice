class Solution {
    public:
        int dp(int idx, vector<int>& memo, vector<int>& nums){
            if (idx >= nums.size()) return 0;
            if (memo[idx] != -1) return memo[idx];
            int take = nums[idx] + dp(idx+2, memo, nums);
            int skip = dp(idx+1, memo, nums);
            memo[idx] = max(take, skip);
            return memo[idx];
        }
        int rob(vector<int>& nums) {
            vector<int> memo(nums.size(), -1);
            return dp(0, memo, nums);
        }
    };