class Solution {
    public:
        bool find_0(vector<vector<int>>& adj, vector<int>& dis_to_Bob, int now, int distance) {
            if (now == 0) return true;
            for (auto &neighbor : adj[now]) {
                if (dis_to_Bob[neighbor] == INT_MAX) {
                    dis_to_Bob[neighbor] = distance+1;
                    if (find_0(adj, dis_to_Bob, neighbor, distance+1)) return true;
                    dis_to_Bob[neighbor] = INT_MAX;
                }
            }
            return false;
        }
        void dfs(vector<vector<int>>& adj, vector<int>& dis_to_Bob, vector<int>& amount, int from, int now, int sum, int distance, int &ans) {
            if (now != 0 && adj[now].size() == 1) { // leaf node
                ans = max(ans, sum);
            }
            else {
                int tmp;
                for (auto &neighbor : adj[now]) {
                    if (neighbor != from) {
                        tmp = sum;
                        if (dis_to_Bob[neighbor] > distance+1) tmp += amount[neighbor], cout << amount[neighbor] <<" ";
                        else if (dis_to_Bob[neighbor] == distance+1) tmp += amount[neighbor]/2, cout << amount[neighbor]<<" ";
                        dfs(adj, dis_to_Bob, amount, now, neighbor, tmp, distance+1, ans);
                    }
                }
            }
        }
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            // init adj
            vector<vector<int>> adj(edges.size()+1);
            int ans = INT_MIN;
            for (auto &edge : edges) {
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
    
            // find the distance from Bob to 0
            vector<int> dis_to_Bob(edges.size()+1, INT_MAX);
            dis_to_Bob[bob] = 0;
            find_0(adj, dis_to_Bob, bob, 0);
    
            dfs(adj, dis_to_Bob, amount, -1, 0, amount[0], 0, ans);
            return ans;
        }
    };
    
    // 重點是此題是 tree，不會走回頭路