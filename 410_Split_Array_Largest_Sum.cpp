class Solution {
public:
    bool valid(vector<int>& nums, int k, int capacity) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] <= capacity) {
                sum += nums[i];
            }
            else {
                sum = nums[i];
                k--;
                if (k == 0) return false;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end()), r = 1e9;
        int ans;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (valid(nums, k, mid)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

// binary search
// guess the answer and verify it
// how to verify?
// greedily add the number into current sum, if we can't, reset the current sum and quota--
