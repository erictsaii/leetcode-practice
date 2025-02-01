class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if (nums.size() == 1) return true;
        bool is_even = nums[0] % 2 == 0;
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] % 2 == 0) == is_even) {
                return false;
            }
            is_even = (is_even) ? false : true;
        }
        return true;
    }
};