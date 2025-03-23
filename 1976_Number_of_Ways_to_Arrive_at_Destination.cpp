class Solution {
    public:
        int countPaths(int n, vector<vector<int>>& roads) {
            // 建adj list
            vector<vector<pair<int, int>>> adj(n);
            for (auto &r : roads) {
                adj[r[0]].push_back({r[1], r[2]});
                adj[r[1]].push_back({r[0], r[2]});
            }
    
            // min heap
            priority_queue <pair<long long, int>, vector<pair<long long, int>>, greater<>> min_heap;
    
            vector<long long> dis(n, LLONG_MAX);
            vector<int> ways(n, 0);
    
            dis[0] = 0;
            ways[0] = 1;
    
            min_heap.push({0, 0}); // dis, node
    
            while(!min_heap.empty()) {
                long long curr_dis = min_heap.top().first;
                int curr_node = min_heap.top().second;
                min_heap.pop();
    
                for (auto& [neighbor_node, neighbor_weight] : adj[curr_node]) {
                    if (curr_dis + neighbor_weight < dis[neighbor_node]) {
                        dis[neighbor_node] = curr_dis + neighbor_weight;
                        ways[neighbor_node] = ways[curr_node];
                        min_heap.push({dis[neighbor_node], neighbor_node});
                    }
                    else if (curr_dis + neighbor_weight == dis[neighbor_node]) {
                        ways[neighbor_node] = (ways[neighbor_node] + ways[curr_node]) % (int)(1e9+7);
                    }
                }
            }
            return ways[n-1];
        }
    };
    
    