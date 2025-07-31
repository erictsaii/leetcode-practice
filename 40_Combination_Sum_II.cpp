class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& candidates, vector<int>& v, int sum, int target, int start) {
        if (sum > target) return;
        else if (sum == target) ans.push_back(v);
        else {
            for (int i = start; i < candidates.size(); i++) {
                if (i > start && candidates[i] == candidates[i-1]) continue;
                if (sum + candidates[i] <= target) {
                    v.push_back(candidates[i]);
                    backtrack(candidates, v, sum + candidates[i], target, i + 1);
                    v.pop_back();
                }
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        backtrack(candidates, v, 0, target, 0);
        return ans;
    }
};
