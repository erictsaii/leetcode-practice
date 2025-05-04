class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            vector<vector<int>> v(10, vector<int>(10, 0));
            int ans = 0;
    
            for (int i = 0; i < dominoes.size(); i++) {
                int a = dominoes[i][0], b = dominoes[i][1];
                if (a > b) swap(a, b);
                v[a][b]++;
            }
    
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (v[i][j] >= 2) ans += v[i][j] * (v[i][j]-1) / 2;
                }
            }
    
            return ans;
        }
    };