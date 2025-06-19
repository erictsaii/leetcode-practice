class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int min_val = nums[0];
        int ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - min_val > k) {
                ans++;
                min_val = nums[i];
            }
        }

        return ans;
    }
};

// 1 2 3 5 6
