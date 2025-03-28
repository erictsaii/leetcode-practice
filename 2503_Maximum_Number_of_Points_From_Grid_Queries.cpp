class Solution {
    public:
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int m = grid.size(), n = grid[0].size(), k = queries.size();
            vector<int> ans(k, 0);
            unordered_map<int, int> memo;
            vector<vector<bool>> visited(m, vector<bool>(n, false));
    
            // copy queries
            vector<int> sorted_queries = queries;
            sort(sorted_queries.begin(), sorted_queries.end());
    
            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
    
            int cnt = 0;
            q.push({grid[0][0], 0, 0});
            visited[0][0] = true;
            for (int j = 0; j < sorted_queries.size(); j++) {
                while (!q.empty() && sorted_queries[j] > get<0>(q.top())) {
                    int y = get<1>(q.top()), x = get<2>(q.top());
                    q.pop();
                    cnt++;
                    for (int i = 0; i < 4; i++) {
                        int nxt_y = dy[i] + y, nxt_x = dx[i] + x;
                        if (0<=nxt_y && nxt_y<m && 0<=nxt_x && nxt_x<n && !visited[nxt_y][nxt_x]) {
                            visited[nxt_y][nxt_x] = true;
                            q.push({grid[nxt_y][nxt_x], nxt_y, nxt_x});
                        }
                    }
                }
                memo[sorted_queries[j]] = cnt;
            }
    
            for (int i = 0; i < k; i++) {
                ans[i] = memo[queries[i]];
            }
    
            return ans;
        }
    };
    