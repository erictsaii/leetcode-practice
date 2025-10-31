class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int max_left = values[0];

        int ans = -1;
        for (int i = 1; i < n; i++) {
            ans = max(ans, values[i] + max_left - i);
            max_left = max(max_left, values[i] + i);
        }
        return ans;
    }
};
