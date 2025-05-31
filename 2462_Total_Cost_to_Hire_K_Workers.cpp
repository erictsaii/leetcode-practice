class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int head = 0, tail = n-1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < candidates; i++) {
            pq.push({costs[head], head});
            head++;
        }
        for (int i = 0; i < candidates && head <= tail; i++) {
            pq.push({costs[tail], tail});
            tail--;
        }

        long long ans = 0;
        for (int i = 0; i < k; i++) {
            auto now = pq.top();
            pq.pop();
            ans += now.first;

            if (head <= tail) {
                if (now.second < head) {
                    pq.push({costs[head], head});
                    head++;
                }
                else {
                    pq.push({costs[tail], tail});
                    tail--;
                }
            }
        }

        return ans;
    }
};

