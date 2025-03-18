class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int ans = 0, l = 0, r = 0, sum = 0;
    
            while (r < nums.size()) {
                if ((sum & nums[r]) == 0) {
                    sum += nums[r];
                    r++;
                }
                else {
                    while ((sum & nums[r]) != 0) {
                        sum -= nums[l];
                        l++;
                    }
                }
                ans = max(r - l, ans);
            }
    
            return ans;
        }
    };
    