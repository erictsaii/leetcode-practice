class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int l = 0, r = nums.size() - 1, mid;
            int upper = nums.size(), lower = nums.size();
            while (l <= r) {
                mid = (l + r) / 2;
                if (nums[mid] <= 0) {
                    l = mid + 1;
                } 
                else {
                    r = mid - 1;
                    upper = mid;
                }
            }
            l = 0;
            r = nums.size() - 1;
            while (l <= r) {
                mid = (l + r) / 2;
                if (nums[mid] < 0) {
                    l = mid + 1;
                } 
                else {
                    r = mid - 1;
                    lower = mid;
                }
            }
    
            return max((int)nums.size() - upper, lower);
        }
    };
    
    // the concept of lower bound and upper bound