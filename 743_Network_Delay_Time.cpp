class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n+1, INT_MAX);
        vector<vector<pair<int, int>>> adj(n+1); // v, w

        dis[k] = 0;
        for (auto& time : times) {
            int u = time[0], v = time[1], w = time[2];
            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while (!pq.empty()) {
            int now = pq.top().second;
            pq.pop();
            for (auto& neighbor : adj[now]) {
                int v = neighbor.first, w = neighbor.second;
                if (dis[v] > dis[now] + w) {
                    dis[v] = dis[now] + w;
                    pq.push({dis[v], v});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dis[i] == INT_MAX) return -1;
            ans = max(ans, dis[i]);
        }
        return ans;
    }
};
