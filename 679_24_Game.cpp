class Solution {
public:
    const double EPS = 1e-6;

    vector<double> compute(double a, double b) {
        vector<double> possible;
        possible.push_back(a + b);
        possible.push_back(a - b);
        possible.push_back(b - a);
        possible.push_back(a * b);
        if (fabs(b) > EPS) possible.push_back(a / b);
        if (fabs(a) > EPS) possible.push_back(b / a);
        return possible;
    }

    bool dfs(vector<double>& nums) {
        if (nums.size() == 1) {
            return fabs(nums[0] - 24.0) < EPS;
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1 ; j < nums.size(); j++) {

                vector<double> next;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }

                vector<double> possible = compute(nums[i], nums[j]);
                for (auto& p : possible) {
                    next.push_back(p);
                    if (dfs(next)) return true;
                    next.pop_back();
                }
            }
        }

        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (const int& card : cards) nums.push_back(card);
        return dfs(nums);
    }
};
