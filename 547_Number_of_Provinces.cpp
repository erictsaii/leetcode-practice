class Solution {
public:
    void dfs(vector<bool>& visited, int now, vector<vector<int>>& isConnected) {
        visited[now] = true;
        for (int i = 0 ; i < isConnected[now].size(); i++) {
            if (isConnected[now][i] && !visited[i]) {
                dfs(visited, i, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(visited, i, isConnected);
                ans++;
            }
        }

        return ans;
    }
};