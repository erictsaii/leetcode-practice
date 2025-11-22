class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        int ans = n-1;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (mid & 1) {
                if (mid-1 < 0) break;
                if (nums[mid] != nums[mid-1]) {
                    ans = mid-1;
                    r = mid-1;
                }      
                else {
                    l = mid+1;
                }
            
            }
            else {
                if (mid+1 >= n) break;
                if (nums[mid] != nums[mid+1]) {
                    ans = mid;
                    r = mid-1;
                }
                else {
                    l  = mid+1;
                }
            }
        }
        return nums[ans];
    }
};


// the length must be odd
// sorted
// binary search
// TTTFFFF
// the answer index must be even (0-indexed)
// the condition: nums[i] != nums[i+1] if odd, if even, nums[i]==nums[i+1]
// and i need to find the first element satisfy the condition
