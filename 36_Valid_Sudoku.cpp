class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check each row
        for (int i = 0; i < 9; i++) {
            unordered_set<char> s;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                else if (s.count(board[i][j])) return false;
                s.insert(board[i][j]);
            }
        }

        // check each column
        for (int i = 0; i < 9; i++) {
            unordered_set<char> s;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;
                else if (s.count(board[j][i])) return false;
                s.insert(board[j][i]);
            }
        } 

        // check the grid
        for (int i = 0; i < 9; i+=3) {
            for (int j = 0; j < 9; j+=3) {
                unordered_set<char> s;
                for (int y = i; y < i+3; y++) {
                    for (int x = j; x < j+3; x++) {
                        if (board[y][x] == '.') continue;
                        else if (s.count(board[y][x])) return false;
                        s.insert(board[y][x]);
                    }
                }
            }
        }

        return true;
    }
};
