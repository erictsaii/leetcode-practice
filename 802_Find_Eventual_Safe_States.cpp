class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> inverted_graph(graph.size());
        queue<int> terminal_node;
        vector<int> ans;
        vector<int> cnt(graph.size());
        for (int i = 0; i < graph.size(); i++) {
            cnt[i] = graph[i].size();
            if (cnt[i] == 0) terminal_node.push(i);
            for (auto v : graph[i]) {
                inverted_graph[v].push_back(i);
            }
        }

        int curr;
        while(!terminal_node.empty()) {
            curr = terminal_node.front();
            ans.push_back(curr);
            terminal_node.pop();

            for (auto v: inverted_graph[curr]) {
                cnt[v]--;
                if (cnt[v] == 0) terminal_node.push(v);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};