class Solution {
    public:
        string dfs(int n) {
            if (n == 1) return "1";
            string prev_str = dfs(n-1);
            int cnt = 1;
            string result = "";
            char prev = prev_str[0];
    
            for (int i = 1; i < prev_str.size(); i++) {
                if (prev_str[i] == prev) {
                    cnt++;
                }
                else {
                    result += to_string(cnt) + prev;
                    cnt = 1;
                    prev = prev_str[i];
                }
            }
            // handle last
            result += to_string(cnt) + prev;
            return result;
        }
        string countAndSay(int n) {
            return dfs(n);
        }
    };