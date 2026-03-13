using ll = long long;
class Solution {
public:
    bool valid(int mountainHeight, vector<int>& workerTimes, ll guess) {
        ll result = 0;

        for (auto& workerTime : workerTimes) {
            ll curr = (-1 + sqrt(1 + 8.0 * ((double)guess / (double)workerTime))) / 2.0;
            result += curr;
        }

        return mountainHeight <= result;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll l = 1, r = 1e18;
        ll ans = 0;

        while (l <= r) {
            ll mid = (l + r) / 2;
            if (valid(mountainHeight, workerTimes, mid)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};




// n(n+1) = 2*x
// nn + n - 2*x = 0;

// n = (-1 + sqrt(1 + 8x))  / 2
