class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor_sum = 0;
        for (auto& num : nums) xor_sum ^= num;
        return xor_sum;
    }
};