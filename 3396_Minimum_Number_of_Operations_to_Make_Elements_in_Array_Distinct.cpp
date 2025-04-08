class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            int start_duplicate_idx = -1;
            vector<bool> v(101, false);
            for (int i = nums.size()-1; i >= 0; i--) {
                if (v[nums[i]] == true) {
                    start_duplicate_idx = i;
                    break;
                }
                v[nums[i]] = true;
            }
            if (start_duplicate_idx == -1) return 0;
            return start_duplicate_idx / 3 + 1;
        }
    };