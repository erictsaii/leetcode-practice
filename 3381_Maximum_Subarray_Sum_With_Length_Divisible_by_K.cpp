class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans = LLONG_MIN;
        vector<long long> smallest_prefix(k);
        long long curr_prefix = 0;

        for (int i = 0; i < k-1; i++) {
            curr_prefix += nums[i];
            smallest_prefix[i] = curr_prefix;
        }

        for (int i = k-1; i < nums.size(); i++) {
            curr_prefix += nums[i];
            ans = max(ans, curr_prefix - smallest_prefix[i % k]);
            smallest_prefix[i % k] = min(smallest_prefix[i % k], curr_prefix);
        }
        return ans;
    }
};
