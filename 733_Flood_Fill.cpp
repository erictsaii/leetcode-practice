class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        int m = image.size(), n = image[0].size();
        int start_color = image[sr][sc];
        queue<pair<int, int>> q;

        image[sr][sc] = color;
        q.push({sr, sc}); // y, x

        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        while (!q.empty()) {
            int y = q.front().first, x = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int n_y = dy[i] + y;
                int n_x = dx[i] + x;
                if (0<=n_y && n_y<m && 0<=n_x && n_x<n && image[n_y][n_x]==start_color) {
                    image[n_y][n_x] = color;
                    q.push({n_y, n_x});
                }
            }
        }

        return image;
    }
};
