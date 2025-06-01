class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(int pos, vector<int>& v, int k, int n, int sum, int start) {
        if (pos == k) {
            if (sum == n) ans.push_back(v);
        }
        else {
            for (int i = start; i <= 9; i++) {
                v.push_back(i);
                backtrack(pos+1, v, k, n, sum+i, i+1);
                v.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        backtrack(0, v, k, n, 0, 1);
        return ans;
    }
};
