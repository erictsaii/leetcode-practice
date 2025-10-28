class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int total = 0;
        for (auto& num : nums) total += num;

        int left = 0, right = total;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (right > left && right - left == 1) ans++;
                else if (left > right && left - right == 1) ans++;
                else if (left == right) ans += 2;
            }
            else {
                left += nums[i];
                right -= nums[i];
            }
        }
        return ans;
    }
};
