class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> s;
        int max_val = -101;

        for (auto& num : nums) {
            max_val = max(max_val, num);
            if (num > 0) {
                s.insert(num);
            }
        }
        int ans = 0;
        for (auto& i : s) {
            ans += i;
        }
        return (max_val > 0) ? ans : max_val;
    }
};

// 1536794
// 1 3 4 5 6 7 9
