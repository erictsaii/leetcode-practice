class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left_idx(n, 0);
        vector<int> right_idx(n, n-1);
        stack<int> stk;

        stk.push(0);
        for (int i = 1; i < n; i++) {
            while (!stk.empty() && arr[i] < arr[stk.top()]) {
                right_idx[stk.top()] = i-1;
                stk.pop();
            }
            stk.push(i);
        }
        
        stk = stack<int>();
        stk.push(n-1);
        for (int i = n-2; i >= 0; i--) {
            while (!stk.empty() && arr[i] <= arr[stk.top()]) {
                left_idx[stk.top()] = i+1;
                stk.pop();
            }
            stk.push(i);
        }

        int MOD = 1e9 + 7;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long l = i - left_idx[i] + 1;
            long long r = right_idx[i] - i + 1;

            int result = (((l * r) % MOD) * arr[i]) % MOD;

            ans = (ans + result) % MOD;
        }

        return ans;
    }
};

