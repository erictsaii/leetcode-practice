class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
        queue<pair<int,int>> q;
 
        vector<vector<int>> height(m, vector<int>(n, -1));

        // init height 0 (water)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) { //is water
                    height[i][j] = 0;
                    q.push({i, j}); 
                }
            }
        }
        pair<int,int> cur;
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int next_i = dy[k] + cur.first;
                int next_j = dx[k] + cur.second;
                if ((0 <= next_j) && (next_j < n) && (0 <= next_i) && (next_i < m) && height[next_i][next_j] == -1) {
                    height[next_i][next_j] = height[cur.first][cur.second] + 1;
                    q.push({next_i, next_j}); 
                }
            }
        }

        return height;
    }
};