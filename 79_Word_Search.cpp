class Solution {
public:
    bool ans = false;
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

    void dfs(vector<vector<bool>>& visited, vector<vector<char>>& board, int y, int x, int pos, string& word, int m, int n) {
        if (pos == word.size()) ans = true;
        else {
            for (int i = 0; i < 4 && !ans; i++) {
                int nx = dx[i] + x;
                int ny = dy[i] + y;
                if (0<=ny && ny<m && 0<=nx && nx<n && !visited[ny][nx] && board[ny][nx]==word[pos]) {
                    visited[ny][nx] = true;
                    dfs(visited, board, ny, nx, pos+1, word, m, n);
                    visited[ny][nx] = false;
                }
            }
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m && !ans; i++) {
            for (int j = 0; j < n && !ans; j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    dfs(visited, board, i, j, 1, word, m, n);
                    visited[i][j] = false;
                }
            }
        }

        return ans;
    }
};
