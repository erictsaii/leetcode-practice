class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            for (int &n : nums) if (k > n) return -1;
            nums.push_back(k);
            sort(nums.begin(), nums.end());
            int prev = nums[0];
            int ans = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (prev != nums[i]){
                    ans++;
                    prev = nums[i];
                }
            }
            return ans;
        }
    };