class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 0, dec = 0, curr = 1;

        // increase
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i+1]) {
                curr++;
            }
            else {
                inc = max(inc, curr);
                curr = 1;
            }
        }
        inc = max(inc, curr);

        // decrease
        curr = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i+1]) {
                curr++;
            }
            else {
                dec = max(dec, curr);
                curr = 1;
            }
        }
        dec = max(dec, curr);

        return max(inc, dec);
    }
};