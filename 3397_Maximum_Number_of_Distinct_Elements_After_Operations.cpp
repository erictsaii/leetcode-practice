class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int max_val = INT_MIN;

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] + k <= max_val) continue;

            max_val = max(nums[i] - k, max_val+1);
            ans++;
        }
        return ans;
    }
};
