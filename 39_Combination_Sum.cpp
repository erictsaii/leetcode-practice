class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& candidates, int target, int sum, vector<int>& now, int start) {
        if (sum == target) ans.push_back(now);
        else {
            for (int i = start; i < candidates.size(); i++) {
                if (sum > target) break;
                now.push_back(candidates[i]);
                backtrack(candidates, target, sum + candidates[i], now, i);
                now.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;

        backtrack(candidates, target, 0, tmp, 0);

        return ans;
    }
};
