class Solution {
public:
    vector<tuple<int, int, int>> jobs;
    int find_next_no_conflict_index(int l, int r, int target) {
        int ans = jobs.size();
        while (l <= r) {
            int mid = (l + r) / 2;
            if (target <= get<0>(jobs[mid])) {
                r = mid - 1;
                ans = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }

    int dp(int idx, vector<int>& memo) {
        if (idx >= memo.size()) return 0;
        if (memo[idx] != -1) return memo[idx];
        int skip = dp(idx+1, memo);
        int next_idx = find_next_no_conflict_index(idx+1, memo.size()-1, get<1>(jobs[idx]));
        int take = get<2>(jobs[idx]) + dp(next_idx, memo);
        memo[idx] = max(skip, take);
        return memo[idx];
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        jobs.assign(n, {}); // start, end, profit

        for (int i = 0; i < n; i++) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end());

        vector<int> memo(n, -1);
        return dp(0, memo);
    }
};
