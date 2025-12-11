class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<priority_queue<int, vector<int>, greater<>>> top_k_neighbors(n);

        for(auto& e : edges) {
            if (vals[e[1]] > 0) top_k_neighbors[e[0]].push(vals[e[1]]);
            if (top_k_neighbors[e[0]].size() > k) top_k_neighbors[e[0]].pop();
            if (vals[e[0]] > 0) top_k_neighbors[e[1]].push(vals[e[0]]);
            if (top_k_neighbors[e[1]].size() > k) top_k_neighbors[e[1]].pop();
        }

        int ans = -1e5;
        for (int i = 0; i < n; i++) {            
            int sum = vals[i];
            while (top_k_neighbors[i].size()) {
                sum += top_k_neighbors[i].top();
                top_k_neighbors[i].pop();
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
