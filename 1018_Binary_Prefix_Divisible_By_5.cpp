class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans(n);
        int prefix = 0;

        for (int i = 0; i < n; i++) {
            prefix <<= 1;
            prefix += nums[i];
            prefix %= 5;
            if (!prefix) ans[i] = true;
            else ans[i] = false;
        }
        return ans;
    }
};

// prefix = (0 + 0) * 2 + 1 = 1
// prefix %= 5;

// mod by 5?
// [0,1,1,1,1]
// 0, 1, 3, 7, 15
// 0, 1, 3, 2, 5
