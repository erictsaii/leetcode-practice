class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m; // prefix % k -> freq
        int prefix = 0;

        m[0] = 1;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            int remain = ((prefix % k) + k) % k;

            ans += m[remain];
            m[remain]++;
        }
        return ans;
    }
};


// divisible by k: sum % k == 0
