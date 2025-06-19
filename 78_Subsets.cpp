class Solution {
public:
    vector<vector<int>> ans;

    void all_set(int idx, vector<int>& nums, vector<int>& now) {
        if (idx == nums.size()) {
            ans.push_back(now);
        }
        else {
            now.push_back(nums[idx]);
            all_set(idx+1, nums, now); // pick nums[idx]
            now.pop_back();
            all_set(idx+1, nums, now); // skip nums[idx]
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        all_set(0, nums, tmp);
        return ans;
    }
};
