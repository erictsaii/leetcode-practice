class Solution {
public:
    int memo[10001] = {0};

    int solve(int idx, vector<pair<int, int>>& freq) {
        if (idx >= freq.size()) return 0;
        if (memo[idx]) return memo[idx];

        int take = freq[idx].first * freq[idx].second;
        if (idx+1 < freq.size() && freq[idx+1].first == freq[idx].first+1) take += solve(idx+2, freq);
        else take += solve(idx+1, freq);

        int skip = solve(idx+1, freq);
        return memo[idx] = max(take, skip);
    }

    int deleteAndEarn(vector<int>& nums) {
        map<int, int> m;
        for (auto& num : nums) m[num]++;

        vector<pair<int, int>> freq; // val, freq
        for (auto& i : m) {
            freq.push_back({i.first, i.second});
        }
        return solve(0, freq);
    }
};

//  2 2 2 3 3 3 4 4

// picking from the largest sum won't work
