class Solution {
public:
    int memo[20][20] = {0};

    int solve(int l, int r, vector<int>& nums) {
        if (l > r) return 0;
        if (memo[l][r]) return memo[l][r];

        int take_front = nums[l] - solve(l+1, r, nums);
        int take_end = nums[r] - solve(l, r-1, nums);
        return memo[l][r] = max(take_front, take_end);
    }

    bool predictTheWinner(vector<int>& nums) {
        return solve(0, nums.size()-1, nums) >= 0;
    }
};

// 1 10
// 1 10 2

// dp(int l, int r)

// take_front = -dp(l+1, r) + nums[l];
// take_end = -dp(l, r-1) + nums[r]
// return max(take_front, take_end)

