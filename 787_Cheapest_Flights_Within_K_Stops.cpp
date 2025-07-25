class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dis(n, 1e7);
        vector<int> tmp(n, 1e7);
        vector<vector<vector<int>>> adj(n);
        queue<int> q;

        // build adj
        for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]}); // dst, price
        }

        dis[src] = 0;
        q.push(src);

        k++;
        while (!q.empty() && k) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int now = q.front();
                q.pop();
                for (auto& edge : adj[now]) {
                    if (dis[now] + edge[1] < dis[edge[0]]) {
                        tmp[edge[0]] = min(tmp[edge[0]], dis[now] + edge[1]);
                        q.push(edge[0]);
                    }
                }
            }
            dis = tmp;
            k--;
        }

        return (dis[dst] == 1e7) ? -1 : dis[dst];
    }
};
