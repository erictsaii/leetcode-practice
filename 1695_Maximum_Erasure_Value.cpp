class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        int start = 0;
        unordered_set<int> s;

        for (int end = 0; end < nums.size(); end++) {
            while (s.count(nums[end])) {
                s.erase(nums[start]);
                sum -= nums[start];
                start++;
            }
            sum += nums[end];
            s.insert(nums[end]);
            ans = max(sum, ans);
        }
        return ans;
    }
};
