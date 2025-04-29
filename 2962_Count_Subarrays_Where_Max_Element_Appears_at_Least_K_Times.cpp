class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int max_value = *max_element(nums.begin(), nums.end());
            int cnt = 0, start = 0, n = nums.size();
            long long ans = 0;
            for (int end = 0; end < n; end++) {
                if (max_value == nums[end]) {
                    cnt++;
                }
                while (cnt >= k) {
                    ans += n - end;
                    if (nums[start] == max_value) cnt--;
                    start++;
                }
            }
    
            return ans;
        }
    };