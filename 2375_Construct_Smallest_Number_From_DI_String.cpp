class Solution {
    public:
        bool backtracking(string& pattern, vector<bool>& used, int index, string& ans) {
            if (index == pattern.size()) return true;
            else {
                for (int i = 1; i <= 9; i++) {
                    if (used[i]) continue;
                    if ((pattern[index] == 'I' && i > ans[index] - '0') || (pattern[index] == 'D' && i < ans[index] - '0')) {
                        ans += to_string(i);
                        used[i] = true;
                        if (backtracking(pattern, used, index+1, ans)) return true;
                        ans.pop_back();
                        used[i] = false;
                    }
                }
                return false;
            }
        }
        string smallestNumber(string pattern) {
            vector<bool> used(10, false);
            string ans;
            for (int i = 1; i <= 9; i++) {
                ans = to_string(i);
                used[i] = true;
                if (backtracking(pattern, used, 0, ans)) break;
                used[i] = false;
            }
    
            return ans;
        }
    };