class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            int m = grid.size();
            int n = grid[0].size();
            int tmp = grid[0][0] % x;
            vector<int> sorted;
    
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if ((grid[i][j] % x) != tmp) return -1;
                    sorted.push_back(grid[i][j]);
                }
            }
    
            sort(sorted.begin(), sorted.end());
    
            int ans = 0;
            int median = sorted[sorted.size()/2];
    
            for (int i = 0; i < sorted.size(); i++) {
               ans += abs(median - sorted[i]) / x;
            }
    
            return ans;
        }
    };