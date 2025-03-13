class Solution {
    public:
        bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            vector<int> v(nums.size(), 0);
            int sum = 0;
            for (int i = 0; i < queries.size(); i++) {
                v[queries[i][0]]++;
                if (queries[i][1] + 1 < v.size()) v[queries[i][1] + 1]--;
            }
            for (int i = 0; i < v.size(); i++) {
                sum += v[i];
                if (sum < nums[i]) return false;
            }
            return true;
        }
    };