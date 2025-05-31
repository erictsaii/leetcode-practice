class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> v(n); // efficiency, speed
        for(int i = 0; i < n; i++) v[i] = {efficiency[i], speed[i]};
        sort(v.begin(), v.end());

        long long ans = 0, sum = 0;
        int MOD = 1e9 + 7;
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        for (int i = n-1; i >= 0; i--) {
            sum += v[i].second;
            pq.push(v[i].second);
            ans = max(ans, (1LL * sum * v[i].first));
            if (pq.size()==k) {
                sum -= pq.top();
                pq.pop();
            }
        }

        return ans % MOD;
    }
};
