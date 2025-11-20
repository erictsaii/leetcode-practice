class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }

    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int a = -1, b = -1;
        int ans = 0;

        for (int i = 0; i < intervals.size(); i++) {
            if (a > b) swap(a, b); // a < b

            int start = intervals[i][0], end = intervals[i][1];
            if (a < start && b < start) {
                a = end-1;
                b = end;
                ans += 2;
            }
            else if (a < start) {
                if (end != b) a = end;
                else a = end-1;
                ans++;
            }
        }
        return ans;
    }
};



// input: intervals
// return minimum size of a containing set
