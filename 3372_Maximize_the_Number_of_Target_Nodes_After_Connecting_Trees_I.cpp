class Solution {
public:

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(m);

        // build adj
        for (auto& e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        // find max val in tree 2
        int max_val = 0;
        if (k > 0) {
            for (int i = 0; i < m; i++) {
                int cnt = 0;
                int step = 0;
                queue<int> q;
                vector<bool> visited(m, false);
                q.push(i);
                visited[i] = true;
                cnt++;
                while (!q.empty() && step < k-1) {
                    int size = q.size();
                    for (int j = 0; j < size; j++) {
                        int now = q.front();
                        q.pop();
                        for (auto& neighbor : adj2[now]) {
                            if (!visited[neighbor]) {
                                visited[neighbor] = true;
                                cnt++;
                                q.push(neighbor);
                            }
                        }
                    }
                    step++;
                }
                max_val = max(max_val, cnt);
            }
        }

        // count tree 1
        vector<int> ans(n, max_val);

        for (int i = 0; i < n; i++) {
            int step = 0;
            queue<int> q;
            vector<bool> visited(n, false);
            q.push(i);
            visited[i] = true;
            ans[i]++;
            while (!q.empty() && step < k) {
                int size = q.size();
                for (int j = 0; j < size; j++) {
                    int now = q.front();
                    q.pop();
                    for (auto& neighbor : adj1[now]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            ans[i]++;
                            q.push(neighbor);
                        }
                    }
                }
                step++;
            }
        }

        return ans;
    }
};
