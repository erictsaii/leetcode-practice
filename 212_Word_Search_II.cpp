class Solution {
public:
    int m, n;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    vector<string> ans;

    class Node {
    public:
        unordered_map<char, Node*> next;
        string str = "";
    };

    void dfs(int y, int x, Node* curr, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        if (curr->str != "") {
            ans.push_back(curr->str);
            curr->str = "";
        }

        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + y, nx = dx[i] + x;
            if (0<=ny && ny<m && 0<=nx && nx<n && !visited[ny][nx] && curr->next.count(board[ny][nx])) {
                visited[ny][nx] = true;
                dfs(ny, nx, curr->next[board[ny][nx]], board, visited);
                visited[ny][nx] = false;
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        Node* dummy = new Node();
        Node* curr;
        for (auto& word : words) {
            Node *curr = dummy;
            for (auto& c : word) {
                if (!curr->next.count(c)) {
                    curr->next[c] = new Node();
                }
                curr = curr->next[c];
            }
            curr->str = word;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                if (dummy->next.count(board[i][j])) {
                    visited[i][j] = true;
                    dfs(i, j, dummy->next[board[i][j]], board, visited);
                }
            }
        }

        return ans;
    }
};
