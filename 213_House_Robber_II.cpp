class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int n = nums.size();
        int ans = 0;
        vector<int> take(n, 0), skip(n, 0);

        // take the first one, skip the last one
        take[0] = nums[0];
        for (int i = 1; i < n-1; i++) {
            take[i] = skip[i-1] + nums[i];
            skip[i] = max(take[i-1], skip[i-1]);
        }
        ans = max(take[n-2], skip[n-2]);

        // skip the first one
        take.assign(n, 0);
        skip.assign(n, 0);
        for (int i = 1; i < n; i++) {
            take[i] = skip[i-1] + nums[i];
            skip[i] = max(take[i-1], skip[i-1]);
        }

        ans = max({ans, take[n-1], skip[n-1]});
        return ans;
    }
};
