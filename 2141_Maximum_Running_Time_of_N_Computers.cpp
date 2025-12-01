using ll = long long;
class Solution {
public:
    bool valid(int n, vector<int>& batteries, ll guess, ll quota) {
        for (int i = batteries.size()-n; i < batteries.size(); i++) {
            if (guess > batteries[i]) quota -= guess - batteries[i];
        }
        return quota >= 0;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());

        ll quota = 0;
        for (int i = 0; i < batteries.size()-n; i++) {
            quota += batteries[i];
        }

        ll l = 1, r = 1e14;
        ll ans;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (valid(n, batteries, mid, quota)) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};



// given n, there are n computers
// given batteries array, means ith battery can run batteries[i] units of time
// in the beginning, every computer have one battery

// return maximum minutes to run n computers simultaneously


// TODO:
// sort the batteries array, pick top n largest battery to use in the beginning
// sum up the value of the rest battery
// apply binary search for the answer
// let's say we guess the answer is 100, add each top n battery to 100 from the sum of the rest battery
// O(nlogn)
