class Solution {
public:
    int memo[305][305] = {0};

    int solve(vector<int>& nums, int left, int right) {
        if (memo[left][right] != 0) return memo[left][right];

        int result = 0;
        for (int i = left; i <= right; i++) {
            int tmp = nums[i];
            if (left - 1 >= 0) tmp *= nums[left - 1];
            if (right + 1 < nums.size()) tmp *= nums[right + 1];
            result = max(result, tmp + solve(nums, left, i-1) + solve(nums, i+1, right));
        }

        return memo[left][right] = result;
    }

    int maxCoins(vector<int>& _nums) {
        vector<int> nums;
        nums.push_back(1);
        nums.insert(nums.end(), _nums.begin(), _nums.end());
        nums.push_back(1);

        return solve(nums, 1, nums.size()-2);
    }
};


// divide and conquer
// instead of choosing ith balloon to burst first, we choose ith balloon to burst last
