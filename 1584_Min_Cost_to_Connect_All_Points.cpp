class Solution {
public:
    vector<int> parent;
    vector<int> depth;

    int find(int node) {
        if (parent[node] == -1) return node;
        return parent[node] = find(parent[node]);
    }

    void join(int a, int b) {
        int root1 = find(a);
        int root2 = find(b);
        if (root1 == root2) return;
        else if (depth[root1] > depth[root2]) {
            depth[root1]++;
            parent[root2] = root1;
        }
        else {
            depth[root2]++;
            parent[root1] = root2;
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.assign(n, -1);
        depth.assign(n, 0);

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq; // dis, u, v
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                pq.push({dis, i, j});
            }
        }

        int cnt = 0;
        int ans = 0;
        while (cnt != n-1) {
            auto now = pq.top();
            pq.pop();
            int dis = get<0>(now), u = get<1>(now), v = get<2>(now);
            if (find(u) != find(v)) {
                ans += dis;
                cnt++;
                join(u, v);
            }
        }
        return ans;
    }
};

// union find(判斷有無環) + kruskal(minimum spanning tree)
