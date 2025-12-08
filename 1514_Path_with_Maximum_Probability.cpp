class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> probability(n, 0.0);
        vector<vector<pair<int, double>>> adj(n); // neighbor, prob

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        probability[start_node] = 1.0;

        while (pq.size()) {
            auto [curr_prob, curr_node] = pq.top();
            pq.pop();

            if (curr_node == end_node) return curr_prob;

            for (auto [neighbor, prob] : adj[curr_node]) {
                if (probability[neighbor] < prob * curr_prob) {
                    probability[neighbor] = prob * curr_prob;
                    pq.push({probability[neighbor], neighbor});
                }
            }
        }

        return 0.0;
    }
};
