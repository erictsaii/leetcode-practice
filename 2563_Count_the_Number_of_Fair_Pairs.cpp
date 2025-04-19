class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            long long ans = 0;
            sort(nums.begin(), nums.end());
    
            for (int i = 0; i < nums.size(); i++) {
                int l = i+1, r = nums.size()-1;
                // find lower bound
                int lower_idx = -1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (nums[mid] + nums[i] >= lower) {
                        lower_idx = mid;
                        r = mid - 1;
                    }
                    else {
                        l = mid + 1;
                    }
                }
                // find upper bound
                int upper_idx = -1;
                l = i+1, r = nums.size()-1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (nums[mid] + nums[i] <= upper) {
                        upper_idx = mid;
                        l = mid + 1;
                    }
                    else {
                        r = mid - 1;
                    }
                }
                if (lower_idx!=-1 && upper_idx!=-1) {
                    ans += upper_idx - lower_idx + 1;
                }
            }
    
            return ans;
        }
    };
    
    // 0 1 4 4 5 7 
    
    // for 0:
    // find last >=3 and <=6