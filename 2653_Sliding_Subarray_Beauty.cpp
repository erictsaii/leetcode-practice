class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> cnt(51, 0);

        for (int i = 0; i < k-1; i++) {
            if (nums[i] < 0) cnt[-nums[i]]++;
        }

        vector<int> ans;
        for (int i = k-1; i < nums.size(); i++) {
            if (nums[i] < 0) cnt[-nums[i]]++;

            int tmp = 0;
            int j;
            for (j = 50; j >= 1; j--) {
                tmp += cnt[j];
                if (tmp >= x) break;
            }
            ans.push_back(-j);

            if (nums[i - k + 1] < 0) cnt[-nums[i - k + 1]]--;
        }
        return ans;
    }
};
