class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cliff = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i+1]) cliff++;
        }
        if (nums[n-1] > nums[0]) cliff++;
        return cliff <= 1;
    }
};