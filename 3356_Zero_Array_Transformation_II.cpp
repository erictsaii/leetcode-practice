class Solution {
    public:
        bool can_form_zero(vector<int> &nums, vector<vector<int>>& queries, int right) {
            vector<int> difference_array(nums.size(), 0);
            int l, r, val, sum = 0;
            for (int i = 0; i < right; i++) {
                l = queries[i][0];
                r = queries[i][1];
                val = queries[i][2];
                difference_array[l] += val;
                if (r + 1 < difference_array.size()) difference_array[r + 1] -= val;
            }
            for (int i = 0; i < difference_array.size(); i++) {
                sum += difference_array[i];
                if (sum < nums[i]) return false;
            }
            return true;
        }
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            if (!can_form_zero(nums, queries, queries.size())) return -1;
            int ans;
            int left = 0, right = queries.size(), mid;
            while (left <= right) {
                mid = (left + right) / 2;
                if (can_form_zero(nums, queries, mid)) {
                    ans = mid;
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            return ans;
        }
    };