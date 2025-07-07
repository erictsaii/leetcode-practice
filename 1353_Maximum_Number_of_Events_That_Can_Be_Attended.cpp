class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int max_day = 0;
        int n = events.size();
        for (auto& e : events) {
            max_day = max(max_day, e[1]);
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        int j = 0;
        int ans = 0;
        for (int i = 1; i <= max_day; i++) {
            while (!pq.empty() && pq.top() < i) {
                pq.pop();
            }

            while (j < n && events[j][0] <= i) {
                pq.push(events[j][1]);
                j++;
            }

            if (!pq.empty()) {
                pq.pop();
                ans++;
            }
        }

        return ans;
    }
};
