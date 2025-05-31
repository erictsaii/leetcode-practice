class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> v(n); // wage/quality, idx
        for (int i = 0; i < n; i++) v[i] = {1.0 * wage[i] / quality[i], i};
        sort(v.begin(), v.end());

        priority_queue<int> pq;
        int quality_sum = 0;
        double ans = DBL_MAX;
        for (int i = 0; i < n; i++) {
            if (pq.size() < k-1) {
                quality_sum += quality[v[i].second];
                pq.push(quality[v[i].second]);
                continue;
            }
            quality_sum += quality[v[i].second];
            pq.push(quality[v[i].second]);

            ans = min(ans, 1.0 * quality_sum / quality[v[i].second] * wage[v[i].second]);

            quality_sum -= pq.top();
            pq.pop();
        } 
        return ans;
    }
};

// return the the least money to form a paid group

// paid group:
// 1. k workers  2. everyone get at least his expectation  3. proportional according to quality

// 10   20   5
// 70   50   30

// 7   2.5   6

