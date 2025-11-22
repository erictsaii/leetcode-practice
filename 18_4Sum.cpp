class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int l = j+1, r = n-1;
                while (l < r) {
                    long long sum = 1LL*nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        while (l < n && nums[l-1] == nums[l]) l++;
                    }
                    else if (sum < target) {
                        l++;
                    }
                    else {
                        r--;
                    }
                }
                while (j+1 < n && nums[j] == nums[j+1]) j++;
            }
            while (i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};
