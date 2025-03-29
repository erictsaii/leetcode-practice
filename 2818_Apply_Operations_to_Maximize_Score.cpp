class Solution {
    public:
        long long MOD = 1e9+7;
        long long power(long long base, long long exponent) {
            long long res = 1;
            while (exponent > 0) {
                if (exponent % 2 == 1) {
                    res = ((res * base) % MOD);
                }
    
                base = (base * base) % MOD;
                exponent /= 2;
            }
            return res;
        }
    
        int maximumScore(vector<int>& nums, int k) {
            int n = nums.size();
            // 歐拉篩法找不同質因數個數
            int _max = *max_element(nums.begin(), nums.end());
            vector<int> prime_score(_max+1, 0);
            for (int i = 2; i <= _max; i++) {
                if (prime_score[i] == 0) {
                    for (int j = i; j <= _max; j += i) {
                        prime_score[j]++;
                    }
                }
            }
    
            // 按照val排序
            vector<pair<int, int>> sorted_nums(n); //val, idx
            for (int i = 0; i < n; i++) {
                sorted_nums[i] = {nums[i], i};
            }
            sort(sorted_nums.begin(), sorted_nums.end(), greater<pair<int, int>>());
    
            long long ans = 1LL;
    
            // find the nearest element greater than i (monotonic stack)
            vector<int> l(n, -1);
            vector<int> r(n, n);
            stack<int> stk;
    
            for (int i = 0; i < n; i++) {
                while (!stk.empty() && prime_score[nums[stk.top()]] < prime_score[nums[i]]) {
                    int topIndex = stk.top();
                    stk.pop();
                    r[topIndex] = i;
                }
                if (!stk.empty()) l[i] = stk.top();
    
                stk.push(i);
            }
    
            // 快速冪
            int processingIndex = 0;
            while (k > 0) {
                auto [num, index] = sorted_nums[processingIndex++];
                long long operations = min((long long)k, (long long)(r[index] - index) * (index - l[index]));
                ans = (ans * power(num, operations)) % MOD;
                k -= operations;
            }
           
            return ans;
        }
    };
    
    