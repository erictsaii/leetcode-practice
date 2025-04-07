class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int target = 0;
            for (auto& n : nums) target += n;
            if (target % 2) return false;
            target /= 2;
    
            vector<bool> dp(target+1, false);
            dp[0] = true;
            for (auto& n : nums) {
                for (int i = target; i >= n; i--) {
                    dp[i] = dp[i] || dp[i - n]; 
                }
            }
            return dp[target];
        }
    };
    
    