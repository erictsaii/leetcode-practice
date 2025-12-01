class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;
        vector<int> sign(n-1);

        for (int i = 0; i < n-1; i++) {
            if (arr[i] > arr[i+1]) sign[i] = 1;
            else if (arr[i] < arr[i+1]) sign[i] = -1;
            else sign[i] = 0;
        }

        int prev_sign = sign[0];
        int cnt = (sign[0] == 0) ? 0 : 1;
        int ans = cnt+1;

        for (int i = 1; i < n-1; i++) {
            if (sign[i] == 0) {
                cnt = 0;
                prev_sign = 0;
                continue;
            }

            if (prev_sign == 0 || prev_sign * -1 == sign[i]) {
                cnt++;
            }
            else {
                cnt = 1;
            }
            ans = max(ans, cnt+1);
            prev_sign = sign[i];
        }
        return ans;
    }
};


// the subarray must be contiguous

// 1 means larger, 0 means equal, -1 means less
// [9,4,2,10,7,8,8,1,9]
// 1 1 -1 1 -1 0 1 -1
// O(n)
