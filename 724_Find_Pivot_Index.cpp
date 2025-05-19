class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n, 0);
        
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            sum[i] = tmp;
            tmp += nums[i];
        }
        tmp = 0;
        for (int i = n-1; i >= 0; i--) {
            sum[i] -= tmp;
            tmp += nums[i];
        }
        for (int i = 0; i < n; i++) {
            if (sum[i] == 0) return i;
        }
        return -1;
    }
};