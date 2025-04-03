class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long ans = 0;
            int max_diff = nums[0] - nums[1];
            int max_val = max(nums[0], nums[1]);
    
            for (int k = 2; k < nums.size(); k++) {
                ans = max(ans, 1LL * max_diff * nums[k]);
                max_diff = max(max_diff, max_val - nums[k]);
                max_val = max(max_val, nums[k]);
            }
    
            return ans;
        }
    };