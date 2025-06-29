class Solution {
public:
    int MOD = 1e9 + 7;
    int fast_pow(int x, int n) {
        int result = 1;
        long long p = x;
        while (n > 0) {
            if (n & 1) {
                result = (result * p) % MOD;
            }
            p = (p * p) % MOD;
            n >>= 1;
        }
        return result;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int end = n-1;
        
        int ans = 0;
        for (int start = 0; start < n; start++) {
            while (end >= start && nums[start] + nums[end] > target) {
                end--;
            }
            if (end < start) break;
            ans = (ans + fast_pow(2, end - start)) % MOD;
        }
        return ans;
    }
};
