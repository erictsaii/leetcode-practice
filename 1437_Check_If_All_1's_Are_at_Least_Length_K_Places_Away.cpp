class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last_one_index = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                if (last_one_index != -1 && i-last_one_index-1 < k) return false;
                last_one_index = i;
            }
        }
        return true;
    }
};
