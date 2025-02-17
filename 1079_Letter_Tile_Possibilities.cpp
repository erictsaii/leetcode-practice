class Solution {
    public:
        int dfs(vector<int> &v, int length, int now_length) {
            if (now_length == length) return 1;
            else {
                int sum = 0;
                for (int i = 0; i < 26; i++) {
                    if (v[i] == 0) continue;
                    v[i]--;
                    sum += dfs(v, length, now_length + 1);
                    v[i]++;
                }
                return sum;
            }
        }
        int numTilePossibilities(string tiles) {
            vector<int> v(26, 0);
            int ans = 0;
            for (auto &c : tiles) {
                v[c-'A']++;
            }
            for (int i = 1; i <= tiles.size(); i++) {
                ans += dfs(v, i, 0);
            }
    
            return ans;
        }
    };
    
    // 紀錄字母個數
    // 限制tmp長度 1 ~ N
    