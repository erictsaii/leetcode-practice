class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int cnt = 0;
        int ans = INT_MIN;
        for (int i = 0; i < k; i++) sum += nums[i];
        for (int i = k; i < nums.size(); i++) {
            ans = max(ans, sum);
            sum += nums[i];
            sum -= nums[i-k];
        }
        ans = max(ans, sum);
        return (double)ans / (double)k;
    }
};