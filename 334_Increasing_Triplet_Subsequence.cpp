class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        left[0] = INT_MAX;
        vector<int> right(n);
        right[n-1] = INT_MIN;

        for (int i = 1; i < n; i++) {
            left[i] = min(left[i-1], nums[i-1]);
        }
        for (int i = n-2; i >= 0; i--) {
            right[i] = max(right[i+1], nums[i+1]);
        }
        for (int i = 1; i < n-1; i++) {
            if (left[i]<nums[i] && right[i]>nums[i]) return true;
        }

        return false;
    }
};
