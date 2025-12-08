class Solution {
public:
    int dfs(int curr_idx, vector<vector<int>>& row, vector<vector<int>>& col, vector<vector<int>>& stones, vector<int>& visited) {
        int cnt = 1;
        visited[curr_idx] = true;

        int x = stones[curr_idx][0], y = stones[curr_idx][1];

        for (auto& neighbor : col[x]) {
            if (!visited[neighbor]) {
                cnt += dfs(neighbor, row, col, stones, visited);
            }
        }

        for (auto& neighbor : row[y]) {
            if (!visited[neighbor]) {
                cnt += dfs(neighbor, row, col, stones, visited);
            }
        }

        return cnt;
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> row(1e4+1);
        vector<vector<int>> col(1e4+1);

        for (int i = 0; i < n; i++) {
            int x = stones[i][0];
            int y = stones[i][1];

            row[y].push_back(i);
            col[x].push_back(i);
        }

        vector<int> visited(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans += dfs(i, row, col, stones, visited) - 1;
            }
        }
        return ans;
    }
};
