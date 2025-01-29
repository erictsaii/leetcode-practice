class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int, int>> sorted_nums; // idx, val
        for (int i = 0; i < nums.size(); i++) {
            sorted_nums.push_back({i, nums[i]});
        }
        sort(sorted_nums.begin(), sorted_nums.end(), cmp);

        vector<int> which_set(nums.size());
        vector<int> ans(nums.size());

        vector<multiset<int>> sets;
        sets.push_back({sorted_nums[0].second});
        which_set[sorted_nums[0].first] = sets.size() - 1; // 0-indexed

        for (int i = 1; i < sorted_nums.size(); i++) {
            if (abs(sorted_nums[i].second - sorted_nums[i-1].second) <= limit) {
                sets.back().insert(sorted_nums[i].second);
                which_set[sorted_nums[i].first] = sets.size() - 1;
            }
            else {
                sets.push_back({sorted_nums[i].second});
                which_set[sorted_nums[i].first] = sets.size() - 1;
            }
        }

        for (int i = 0; i < ans.size(); i++) {
            int set_idx = which_set[i];
            ans[i] = *sets[set_idx].begin();
            sets[set_idx].erase(sets[set_idx].begin());
        }

        return ans;
    }
};



