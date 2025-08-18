class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int, vector<int>> node_to_routes;

        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                node_to_routes[routes[i][j]].push_back(i);
            }
        }

        unordered_set<int> visited;
        queue<int> q;
        for (auto& route : node_to_routes[source]) {
            q.push(route);
            visited.insert(route);
        }

        int dis = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int now = q.front();
                q.pop();

                for (auto& stop : routes[now]) {
                    if (stop == target) return dis;
                    for (auto& route : node_to_routes[stop]) {
                        if (!visited.count(route)) {
                            q.push(route);
                            visited.insert(route);
                        }
                    }
                }
            }
            dis++;
        }

        return -1;
    }
};


// 1 2 7 
// 3 6 7

// 1 2 想到 3 6 距離為2
