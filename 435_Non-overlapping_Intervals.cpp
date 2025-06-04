class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> v(n); // end, start
        for (int i = 0; i < n; i++) {
            v[i] = {intervals[i][1], intervals[i][0]};
        }
        sort(v.begin(), v.end());

        int end = INT_MIN;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (v[i].second < end) ans++;
            else end = v[i].first;
        }
        return ans;
    }
};

// 12 13 23 34

// 19 23 34 45

// 23 34 45 19
