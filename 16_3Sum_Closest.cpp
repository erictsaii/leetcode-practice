class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans;
        int n = nums.size();
        int diff = INT_MAX;

        for (int i = 0; i < n-2; i++) {
            int l = i+1, r = n-1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < diff) {
                    diff = abs(sum - target);
                    ans = sum;
                }
                if (sum > target) {
                    r--;
                }
                else {
                    l++;
                }
            }
        }
        
        return ans;
    }
};
