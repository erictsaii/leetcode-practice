class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), cmp);

        int ans = 0;
        for (int i = n-1; i >= 1; i--) {
            int min_y = INT_MAX;
            int Ay = points[i][1];
            for (int j = i-1; j >= 0; j--) {
                if (Ay <= points[j][1] && min_y > points[j][1]) {
                    min_y = points[j][1];
                    ans++;
                }
            }
        }
        return ans;
    }
};
