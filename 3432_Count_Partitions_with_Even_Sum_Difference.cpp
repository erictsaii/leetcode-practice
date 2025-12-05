class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int left_sum = 0, right_sum = 0;
        for (auto& num : nums) right_sum += num;

        int ans = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            left_sum += nums[i];
            right_sum -= nums[i];
            if ((right_sum - left_sum) % 2 == 0) ans++;
        }
        return ans;
    }
};
