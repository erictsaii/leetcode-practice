class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            unordered_map<int, int> total_map;
            unordered_map<int, int> now_map;
            int n = nums.size();
            for (int i = 0; i < n; i++) {
                total_map[nums[i]]++;
            }
            int ans = 0, start = 0;
            for (int i = 0; i < n; i++) {
                now_map[nums[i]]++;
                while (now_map.size() == total_map.size()) {
                    ans += n - i;
                    now_map[nums[start]]--;
                    if (now_map[nums[start]] == 0) now_map.erase(nums[start]);
                    start++;
                }
            }
    
            return ans;
        }
    };