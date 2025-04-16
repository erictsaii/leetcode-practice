class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            int n = nums.size(), start = 0;
            long long ans = 0, pair_num = 0;
            unordered_map<int, int> cnt;
    
            for (int i = 0; i < n; i++) {
                pair_num += cnt[nums[i]];
                cnt[nums[i]]++;
                while (pair_num >= k) {
                    ans += n-i;
                    cnt[nums[start]]--;
                    pair_num -= cnt[nums[start]];
                    start++;
                }     
            }
    
            return ans;
        }
    };