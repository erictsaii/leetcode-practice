class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            vector<int> in_degree(n, 0); // idx of nums, in_degree
            vector<vector<int>> adj(n);
    
            // build adj
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (nums[j] % nums[i] == 0) {
                        adj[i].push_back(j);
                        in_degree[j]++;
                    }
                }
            }
    
            // start topological sort
            queue<int> q;
            vector<int> prev(n, -1);
            int last;
            for (int i = 0; i < n; i++) {
                if (in_degree[i] == 0) q.push(i);
            }
            while (!q.empty()) {
                int now = q.front();
                q.pop();
                for (auto neighbor : adj[now]) {
                    in_degree[neighbor]--;
                    if (in_degree[neighbor] == 0){
                        q.push(neighbor);
                        prev[neighbor] = now;
                    } 
                }
                last = now;
            }
            vector<int> ans;
            for (int i = last; i != -1; i = prev[i]) {
                ans.push_back(nums[i]);
            }
            return ans;
        }
    };
    