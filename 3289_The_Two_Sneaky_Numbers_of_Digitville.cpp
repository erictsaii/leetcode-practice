class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        vector<int> cnt(100, 0);

        for (int i = 0; i < nums.size(); i++) {
            if (cnt[nums[i]]) ans.push_back(nums[i]);
            cnt[nums[i]]++;
        }
        return ans;
    }
};
