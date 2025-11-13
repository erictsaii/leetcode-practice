class Solution {
public:
    bool valid(string& word, string& tmp) {
        if (word.size() != tmp.size()) return false;
        int n = word.size();

        bool from_left = true;
        for (int i = 0; i < n; i++) {
            if (tmp[i] == ' ') continue;
            else if (tmp[i] != word[i]) {
                from_left = false;
                break;
            }
        }

        bool from_right = true;
        for (int i = 0; i < n; i++) {
            if (tmp[i] == ' ') continue;
            else if (tmp[i] != word[n-i-1]) {
                from_right = false;
                break;
            }
        }
        return from_left || from_right;
    }

    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        // horizontal
        string tmp;
        for (int i = 0; i < m; i++) {
            tmp = "";
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '#') {
                    if (valid(word, tmp)) return true;
                    tmp = "";
                } 
                else {
                    tmp.push_back(board[i][j]);
                }
            }
            if (valid(word, tmp)) return true;
        }

        // vertical
        for (int j = 0; j < n; j++) {
            tmp = "";
            for (int i = 0; i < m; i++) {
                if (board[i][j] == '#') {
                    if (valid(word, tmp)) return true;
                    tmp = "";
                } 
                else {
                    tmp.push_back(board[i][j]);
                }
            }
            if (valid(word, tmp)) return true;
        }
        return false;
    }
};



// 放上去word後，他旁邊只能是邊界或'#'
// O(n^2)
