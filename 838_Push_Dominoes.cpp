class Solution {
    public:
        string pushDominoes(string dominoes) {
            int n = dominoes.size();
            vector<int> l(n, INT_MAX);
            vector<int> r(n, INT_MAX);
            string ans = "";
            
            // L
            int prev_idx = -1;
            for (int i = n-1; i >= 0; i--) {
                if (dominoes[i] == 'L') {
                    prev_idx = i;
                }
                else if (dominoes[i] == '.' && prev_idx != -1) {
                    l[i] = prev_idx - i;
                }
                else if (dominoes[i] == 'R') {
                    prev_idx = -1;
                }
            }
            // R
            prev_idx = -1;
            for (int i = 0; i < n; i++) {
                if (dominoes[i] == 'R') {
                    prev_idx = i;
                }
                else if (dominoes[i] == '.' && prev_idx != -1) {
                    r[i] = i - prev_idx;
                }
                else if (dominoes[i] == 'L') {
                    prev_idx = -1;
                }
            }
    
            for (int i = 0; i < n; i++) {
                if (l[i] < r[i]) ans.push_back('L');
                else if (l[i] > r[i]) ans.push_back('R');
                else if (l[i] == INT_MAX && r[i] == INT_MAX) ans.push_back(dominoes[i]);
                else if (l[i] == r[i]) ans.push_back('.');
            }
    
            return ans;
        }
    };