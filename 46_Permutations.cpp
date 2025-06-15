class Solution {
public:
    vector<vector<int>> ans;
    void permutations(vector<int>& nums, vector<int>& visited, vector<int>& now) {
        if (now.size() == nums.size()) ans.push_back(now);
        else {
            for (int i = 0; i < nums.size(); i++) {
                if (!visited[i]) {
                    now.push_back(nums[i]);
                    visited[i] = true;
                    permutations(nums, visited, now);
                    now.pop_back();
                    visited[i] = false;
                }
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> visited(nums.size(), false);
        vector<int> tmp;
        permutations(nums, visited, tmp);
        return ans;
    }
};
