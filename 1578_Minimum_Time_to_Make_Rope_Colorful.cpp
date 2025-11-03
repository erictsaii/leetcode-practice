class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = neededTime[0];
        char prev = colors[0];
        int max_time = neededTime[0];
        int cnt = 1;

        for (int i = 1; i < colors.size(); i++) {
            ans += neededTime[i];

            if (prev == colors[i]) {
                max_time = max(max_time, neededTime[i]);
                cnt++;
            }
            else {
                ans -= max_time;

                max_time = neededTime[i];
                prev = colors[i];
                cnt = 1;
            }
        }
        ans -= max_time;

        return ans;
    }
};
