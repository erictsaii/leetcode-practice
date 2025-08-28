class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int d = 0; d < n; d++) {
            for (int x1 = 0, y1 = d; x1<n && y1<n; x1++, y1++) {
                for (int x2 = 0, y2 = d; x2<n && y2<n; x2++, y2++) {
                    if (grid[y1][x1] > grid[y2][x2]) {
                        swap(grid[y1][x1], grid[y2][x2]);
                    }
                }
            }
        }

        for (int d = 1; d < n; d++) {
            for (int x1 = d, y1 = 0; x1<n && y1<n; x1++, y1++) {
                for (int x2 = d, y2 = 0; x2<n && y2<n; x2++, y2++) {
                    if (grid[y1][x1] < grid[y2][x2]) {
                        swap(grid[y1][x1], grid[y2][x2]);
                    }
                }
            }
        }

        return grid;
    }
};


