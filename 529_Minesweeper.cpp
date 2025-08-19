class Solution {
public:
    int m, n;

    int mine_num(int y, int x, vector<vector<char>>& board) {
        int cnt = 0;

        for (int i = y-1; i <= y+1; i++) {
            for (int j = x-1; j <= x+1; j++) {
                if (0<=i && i<m && 0<=j && j<n && (board[i][j]=='M'||board[i][j]=='X')) cnt++;
            }
        }

        return cnt;
    }

    void solve(int y, int x, vector<vector<char>>& board) {
        if (board[y][x] == 'M') {
            board[y][x] = 'X';
            return;
        }
        else if (board[y][x] == 'E') {
            int cnt = mine_num(y, x, board);
            if (cnt == 0) { // should be 'B' and explore more
                board[y][x] = 'B';

                for (int i = y-1; i <= y+1; i++) {
                    for (int j = x-1; j <= x+1; j++) {
                        if (0<=i && i<m && 0<=j && j<n && board[i][j]=='E') {
                            solve(i, j, board);
                        }
                    }
                }
            }
            else { // should be cnt and return
                board[y][x] = '0' + cnt;
                return;
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size();
        n = board[0].size();
       
        solve(click[0], click[1], board);
        
        return board;
    }
};
