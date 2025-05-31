class Solution {
public:
    void get_xy(int n, int curr, int& y, int& x) {
        curr--;
        y = (n-1) - curr/n;
        if ((n-1) % 2 == (y % 2)) x = curr%n;
        else x = (n-1) - (curr % n);
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<int> q;

        q.push(1);
        visited[1] = true;
        int step = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();
                if (curr == n*n) return step;

                for (int j = curr+1; j <= min(curr+6, n*n); j++) {
                    int y, x;
                    get_xy(n, j, y, x);
                    int next;

                    if (board[y][x] != -1) next = board[y][x];
                    else next = j;

                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};

// next step range: [curr+1, min(curr+6, n^2)]
// if there's snake, ladder in next step, directly go to that grid
// the game ends at sqare: n^2

// if impossiable, return -1
// else return the least number of dice rolls
