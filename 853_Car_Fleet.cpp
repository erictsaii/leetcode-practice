class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> v(n); // pos, time to reach target

        for (int i = 0; i < n; i++) {
            v[i] = {position[i], (double)(target - position[i]) / (double)speed[i]};
        }

        sort(v.begin(), v.end());

        int ans = 1;
        double curr_time = v[n-1].second;
        for (int i = n-2; i >= 0; i--) {
            if (v[i].second > curr_time) {
                ans++;
                curr_time = v[i].second;
            }
        }

        return ans;
    }
};

// 12
// 10 8 0 5 3
// 1  1 12 7 3
