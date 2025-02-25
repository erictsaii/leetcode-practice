class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            int ans = 0, odd = 0, even = 1, now_sum = 0;
            for (int i = 0; i < arr.size(); i++) {
                now_sum += arr[i];
                if (now_sum % 2 == 0) { // even
                    ans += odd;
                    even++;
                }
                else { // odd
                    ans += even;
                    odd++;
                }
    
                ans %= ((int)1e9 + 7);
            }
            return ans;
        }
    };
    
    // how to be odd?
    // even + odd
    // odd  + even
    