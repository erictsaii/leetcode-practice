class Solution {
public:
    vector<vector<string>> ans;

    bool is_palindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void backtrack(int start, string& s, vector<string>& now) {
        if (start == s.size()) {
            ans.push_back(now);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (is_palindrome(s, start, i)) {
                now.push_back(s.substr(start, i - start + 1));
                backtrack(i+1, s, now);
                now.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        backtrack(0, s, tmp);
        return ans;
    }
};
