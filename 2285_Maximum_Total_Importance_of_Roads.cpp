class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);

        for (auto& road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }

        vector<int> degrees(n); 
        for (int i = 0; i < n; i++) {
            degrees[i] = adj[i].size();
        }

        sort(degrees.begin(), degrees.end());

        long long ans = 0;
        for (int i = n-1; i >= 0; i--) {
            ans += 1LL * degrees[i] * (i+1);
        }
        return ans;
    }
};
