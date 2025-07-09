class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums[0] < nums.back()) return nums[0];
        int l = 0, r = nums.size()-1;

        int ans = INT_MAX;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            }
            else {
                ans = min(ans, nums[mid]);
                r = mid - 1;
            }
        }

        return ans;
    }
};

// 5 1 2 3 4
