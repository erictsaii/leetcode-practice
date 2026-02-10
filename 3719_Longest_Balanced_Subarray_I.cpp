class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> evens, odds;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0 && !evens.count(nums[j])) {
                    evens.insert(nums[j]);
                }
                else if (nums[j] % 2 == 1 && !odds.count(nums[j])) {
                    odds.insert(nums[j]);
                }

                if (evens.size() == odds.size()) ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};

