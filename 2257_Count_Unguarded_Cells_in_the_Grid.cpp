class Solution {
public:
    void check(vector<vector<int>>& v, bool& is_guarded, int i, int j) {
        if (v[i][j] == 1) is_guarded = true;
        else if (v[i][j] == 2) is_guarded = false;
        else if (v[i][j] == 0 && is_guarded) v[i][j] = 3;
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> v(m, vector<int>(n, 0)); // 0 = not guarded, 1 = guard, 2 = wall, 3 = guarded

        for (auto& guard : guards) {
            v[guard[0]][guard[1]] = 1;
        }

        for (auto& wall : walls) {
            v[wall[0]][wall[1]] = 2;
        }

        bool is_guarded;
        for (int i = 0; i < m; i++) {
            // dir right
            is_guarded = false;
            for (int j = 0; j < n; j++) {
                check(v, is_guarded, i, j);
            }

            // dir left
            is_guarded = false;
            for (int j = n-1; j >= 0; j--) {
                check(v, is_guarded, i, j);
            }
        }

        for (int j = 0; j < n; j++) {
            // dir down
            is_guarded = false;
            for (int i = 0; i < m; i++) {
                check(v, is_guarded, i, j);
            }

            // dir up
            is_guarded = false;
            for (int i = m-1; i >= 0; i--) {
                check(v, is_guarded, i, j);
            }
        }

        // find unguarded grid
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] == 0) ans++;
            }
        }
        return ans;
    }
};
