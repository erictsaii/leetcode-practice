class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            long long n = nums.size();
            unordered_map<int, long long> m; // result of sub, times
    
            for (int i = 0; i < n; i++) {
                m[nums[i] - i]++;
            }
    
            long long ans = n * (n-1) / 2;
    
            for (auto i : m) {
                if (i.second >= 2) {
                    ans -= i.second * (i.second-1) / 2;
                }
            }   
    
            return ans;
        }
    };