class Solution {
public:
    bool found_ans = false;
    vector<vector<char>> ans;
    bool valid(vector<vector<char>>& board, int y, int x) {
        char target = board[y][x];
        // check vertical and horizontal
        for (int i = 0; i < 9; i++) {
            if (board[i][x] == target && i != y) return false;
            if (board[y][i] == target && i != x) return false;
        } 

        // check block
        int start_y = (y / 3) * 3;
        int start_x = (x / 3) * 3;
        for (int i = start_y; i < start_y+3; i++) {
            for (int j = start_x; j < start_x+3; j++) {
                if (i==y && j==x) continue;
                if (board[i][j] == target) return false;
            }
        }
        return true;
    }
    void backtrack(vector<vector<char>>& board, int y, int x) {
        if (y == board.size()) {
            found_ans = true;
            return;
        }

        if (board[y][x] != '.') {
            if (x == board[0].size()-1) backtrack(board, y+1, 0);
            else backtrack(board, y, x+1);
        }
        else {
            for (char num = '1'; num <= '9'; num++) {
                board[y][x] = num;
                if (valid(board, y, x)) {
                    if (x == board[0].size()-1) backtrack(board, y+1, 0);
                    else backtrack(board, y, x+1);
                }
                if (found_ans) return;
                board[y][x] = '.';
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
};
