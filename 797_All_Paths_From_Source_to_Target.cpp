class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        queue<vector<int>> q; // path
        int n = graph.size();

        q.push({0});
        vector<vector<int>> ans;
        while (q.size()) {
            vector<int> curr_path = q.front();
            int curr_node = q.front().back();
            q.pop();

            if (curr_node == n-1) {
                ans.push_back(curr_path);
                continue;
            }

            for (auto& neighbor : graph[curr_node]) {
                curr_path.push_back(neighbor);
                q.push(curr_path);
                curr_path.pop_back();
            }
        }
        return ans;
    }
};

// TODO:
// BFS
// we'll have a queue to store current_node, current_path
// start from 0, when we see the n-1 node, add the path to answer
