class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int index, vector<int>& now) {
        if (index == nums.size()) {
            ans.push_back(now);
        }
        else {
            now.push_back(nums[index]);
            backtrack(nums, index+1, now);
            now.pop_back();

            // 去重trick
            while (index+1 < nums.size() && nums[index] == nums[index+1]) {
                index++;
            }
            backtrack(nums, index+1, now);
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        backtrack(nums, 0, tmp);
        return ans;
    }
};
