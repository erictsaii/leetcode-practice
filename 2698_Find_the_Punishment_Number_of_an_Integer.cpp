class Solution {
    public:
        bool dfs(int target, string s, int pos, int sum) {
            if (pos == s.size()) {
                return (sum == target) ? true : false;
            }
            else {
                int x;
                bool result = false;
                for (int i = 0; pos + i < s.size(); i++) {
                    x = 0;
                    for (int j = 0; j <= i; j++) {
                        x *= 10;
                        x += s[pos+j]-'0';
                    }
                    result = result || dfs(target, s, pos+i+1, x + sum);
                }
                return result;
            }
        }
        int punishmentNumber(int n) {
            int square;
            string s;
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                square = i * i;
                s = to_string(square);
                if (dfs(i, s, 0, 0)) ans += square;
            }
    
            return ans;
        }
    };
    