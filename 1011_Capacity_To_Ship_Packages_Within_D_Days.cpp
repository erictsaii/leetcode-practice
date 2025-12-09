class Solution {
public:
    bool valid(vector<int>& weights, int capacity, int days) {
        int cnt = 1;
        int curr_capacity = capacity;
        for (int i = 0; i < weights.size(); i++) {
            if (curr_capacity < weights[i]) {
                cnt++;
                curr_capacity = capacity;
            }
            curr_capacity -= weights[i];
        }
        return cnt <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int max_val = *max_element(weights.begin(), weights.end());
        int sum = accumulate(weights.begin(), weights.end(), 0);

        int l = max_val, r = sum;
        int ans;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (valid(weights, mid, days)) {
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

// binary search on answer
