class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            long long n = nums.size(), start = 0;
            long long ans = 0, sum = 0;
            for (long long end = 0; end < n; end++) {
                sum += nums[end];
                while (sum * (end-start+1) >= k) {
                    sum -= nums[start];
                    start++;
                }
                ans += end - start + 1;
            }
    
            return ans;
        }
    };
    