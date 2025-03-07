class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            vector<int> prime;
            vector<bool> visited(right+1, false);
            vector<int> ans(2, -1);
            if (right - left <= 1) return ans;
    
            // build prime table
            for (int i = 2; i <= right; i++) {
                if (!visited[i]) {
                    prime.push_back(i);
                }
                for (int p : prime) {
                    if (p * i > right) break;
                    visited[p * i] = true;
                    if (i % p == 0) break;
                }
            }
    
            // find closest pair
            int sub = INT_MAX;
            for (int i = 0; i < prime.size()-1; i++) {
                if (prime[i] < left) continue;
                if (prime[i+1] - prime[i] < sub) {
                    ans[0] = prime[i];
                    ans[1] = prime[i+1];
                    sub = prime[i+1] - prime[i];
                }
            }
    
            return ans;
        }
    };