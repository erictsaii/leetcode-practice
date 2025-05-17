class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, idx = 0, r = nums.size()-1;

        while (idx <= r) {
            if (nums[idx] == 0) {
                swap(nums[l++], nums[idx++]);
            }
            else if (nums[idx] == 1) {
                idx++;
            }
            else {
                swap(nums[r--], nums[idx]);
            }
        }
    }
};
