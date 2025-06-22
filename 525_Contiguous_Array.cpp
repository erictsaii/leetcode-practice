class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        unordered_map<int, int> m;
        m[0] = -1;

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) sum++;
            else sum--;

            if (m.find(sum) != m.end()) ans = max(ans, i - m[sum]);
            else m[sum] = i;
        }
        return ans;
    }
};
// 0
// -1 0 1 2 3 4 3 2 1
