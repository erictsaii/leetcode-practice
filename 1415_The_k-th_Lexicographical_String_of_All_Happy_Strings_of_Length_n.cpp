class Solution {
    public:
        int cnt = 0 ;
        string ans = "";
        void dfs(string &letter_set, string& tmp, int n, int k, int pos) {
            if (pos == n) {
                cnt++;
                if (cnt == k) ans = tmp;
                return;
            }
            else {
                for (int i = 0; i < 3; i++) {
                    if (tmp.size()==0 || letter_set[i] != tmp.back()) {
                        tmp += letter_set[i];
                        if (cnt < k) dfs(letter_set, tmp, n, k, pos+1);
                        tmp.pop_back();
                    }
                }
            }
        }
        string getHappyString(int n, int k) {
            string letter_set = "abc";
            string tmp = "";
            dfs(letter_set, tmp, n, k, 0);
            return ans;
        }
    };