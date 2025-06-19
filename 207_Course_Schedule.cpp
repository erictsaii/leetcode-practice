class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_degree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for (auto& prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
            in_degree[prerequisite[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int now = q.front();
            q.pop();
            numCourses--;
            for (auto& neighbor : adj[now]) {
                in_degree[neighbor]--;
                if (in_degree[neighbor] == 0) q.push(neighbor);
            }
        }

        return numCourses == 0;
    }
};
