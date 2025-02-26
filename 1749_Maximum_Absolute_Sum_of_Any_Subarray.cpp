class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int sum = 0, ans = 0;
            // find positive max
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];
                if (sum < 0) sum = 0;
                ans = max(sum, ans);
            }
            sum = 0;
            // find negative max
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];
                if (sum > 0) sum = 0;
                ans = max(-sum, ans);
            }
    
            return ans;
        }
    };
    