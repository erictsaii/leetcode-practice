class Solution {
public:
    static bool cmpBySecond(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        
        sort(points.begin(), points.end(), cmpBySecond);

        int ans = 1;
        int end = points[0][1];
        for (int i = 1; i < n; i++) {
            if (points[i][0] > end) {
                end = points[i][1];
                ans++;
            }
        }

        return ans;
    }
};

// 1 4    5 8   1 12   10 16 
