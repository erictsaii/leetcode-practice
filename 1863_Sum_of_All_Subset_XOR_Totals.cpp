class Solution {
    public:
        int ans = 0;
        void backtrack(int pos, vector<int>& nums, int x_or) {
            if (pos == nums.size()) {
                ans += x_or;
            }
            else {
                // skip
                backtrack(pos+1, nums, x_or);
    
                // take
                backtrack(pos+1, nums, x_or ^ nums[pos]);
            }
        }
        int subsetXORSum(vector<int>& nums) {
            backtrack(0, nums, 0);
    
            return ans;
        }
    };