class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int max_freq = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
            max_freq = max(max_freq, cnt[nums[i]]);
        }

        int ans = 0;
        for (auto i : cnt) {
            if (i.second == max_freq) ans += max_freq;
        }
        return ans;
    }
};
