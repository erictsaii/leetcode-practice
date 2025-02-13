class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            long long ans = 0, a, b;
            priority_queue<long long, vector<long long>, greater<long long> > pq;
            for (auto &n: nums) {
                pq.push(n);
            }
    
            while (k > pq.top()) {
                a = pq.top();
                pq.pop();
                b = pq.top();
                pq.pop();
                pq.push(min(a, b) * 2 + max(a, b));
                ans++;
            }
    
            return ans;
        }
    };